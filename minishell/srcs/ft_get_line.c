/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 20:33:07 by kbunel            #+#    #+#             */
/*   Updated: 2017/05/11 21:23:05 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int		get_cmd(char **args, char **env, t_ms *ms)
{
	int			status;
	pid_t		sid;
	int			exit;

	exit = 0;
	if (args[0] && (ft_strchr(args[0], '/') != NULL
				|| ft_get_builtin(args, env) == 0))
	{
		sid = fork();
		if (sid == 0)
		{
			signal(SIGINT, SIG_DFL);
			ft_get_cmd(args, env, ms);
			exit = 1;
		}
		else
			wait(&status);
	}
	return (exit);
}

static void		back_in_args(char **args, int j)
{
	while (args[j] != NULL)
	{
		ft_memdel((void **)&args[j]);
		if (args[j + 1])
			args[j] = ft_strdup(args[j + 1]);
		j++;
	}
}

static int		set_env(char **env, char *arg)
{
	int		i;
	char	*name;
	char	*value;

	i = 0;
	while (arg[i] != '=' && arg[i] != '\0')
		i++;
	name = ft_strsub(arg, 0, i);
	value = ft_strsub(arg, i + 1, ft_strlen(arg) - i - 1);
	ft_setenv(env, name, value);
	ft_memdel((void **)&name);
	ft_memdel((void **)&value);
	return (1);
}

static char		**select_environnement(char **args, char **env)
{
	int		i;
	char	**env_used;
	int		named;

	i = 0;
	named = 0;
	env_used = ft_get_env(env);
	while (args[i] && ft_strcmp(args[i], "env") == 0 && args[i + 1] != NULL)
	{
		back_in_args(args, i);
		while (args[i] && ((ft_strcmp(args[i], "-i") == 0 && named == 0) || ft_strchr(args[i], '=') != NULL))
		{
			if (ft_strcmp(args[i], "-i") == 0 && named == 0)
			{
				ft_free_env(env_used);
				env_used = NULL;
			}
			else if (ft_strchr(args[i], '=') != NULL)
			{
				if (env_used == NULL)
				{
					env_used = ft_memalloc(2);
					env_used[0] = ft_strdup(args[i]);
					env_used[1] = NULL;
					named = 1;
				}
				else
					named = set_env(env_used, args[i]);
			}
			back_in_args(args, i);
		}
	}
	return env_used;
}

static int		execute(t_ms *ms, char **env, int i)
{
	int		j;
	char	**args;
	char	**env_used;
	int		exit;
	int		env_selected;

	
	j = 0;
	exit = 0;
	ft_replacechar(ms->cmd[i], '\t', ' ');
	args = ft_strsplit(ms->cmd[i], ' ');
	env_selected = (args[i] && ft_strcmp(args[i], "env") == 0 && args[i + 1] != NULL) ? 1 : 0;
	env_used = select_environnement(args, env);
	if (args[0] && ft_strcmp(args[0], "exit") == 0)
		exit = 1;
	else
		exit = get_cmd(args, (env_selected == 0) ? env : env_used,  ms);
	if (args)
		ft_free_env(args);
	if (env_used)
		ft_free_env(env_used);
	return (exit);
}

void			ft_get_line(char **env, t_ms *ms)
{
	char		*line;
	int			i;
	int			exit;

	ft_putstr(ms->prompt);
	exit = 0;
	while (exit == 0 && get_next_line(1, &line))
	{
		i = 0;
		ms->cmd = ft_strsplit(line, ';');
		while (exit == 0 && ms->cmd[i])
		{
			exit = execute(ms, env, i);
			ft_memdel((void **)&ms->cmd[i++]);
		}
		ft_memdel((void **)&ms->cmd);
		ms->cmd = NULL;
		if (exit == 0)
			ft_printf(ms->prompt);
		free(line);
	}
}
