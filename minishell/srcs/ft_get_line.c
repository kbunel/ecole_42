/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 20:33:07 by kbunel            #+#    #+#             */
/*   Updated: 2016/11/28 00:19:04 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void		get_cmd(char **args, char **env, t_ms *ms)
{
	int			status;
	pid_t		sid;

	if (args[0] && (ft_strchr(args[0], '/') != NULL
				|| ft_get_builtin(args, env) == 0))
	{
		sid = fork();
		if (sid == 0)
		{
			signal(SIGINT, SIG_DFL);
			ft_get_cmd(args, env, ms);
			exit(1);
			signal(SIGINT, SIG_IGN);
		}
		else
			wait(&status);
	}
}

static char		**get_arg(char ***args, char **env, int i, int j)
{
	int		e;

	e = (ft_strcmp(args[0][1], "-i") == 0) ? 1 : 0;
	while (args[0][i] != NULL)
	{
		ft_memdel((void **)&args[0][i]);
		if (i + 2 < j)
			args[0][i] = ft_strdup(args[0][i + 2]);
		i++;
	}
	if (e == 1)
		return (NULL);
	else
		return (env);
}

static char		**select_env(char ***args, char **env)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (args[0][j] != NULL)
		j++;
	if (args[0][0] != NULL && ft_strcmp(args[0][0], "env") == 0
			&& args[0][1] != NULL)
	{
		if (args[0][1] != NULL && args[0][1][0] == '-')
			return (get_arg(args, env, i, j));
		while (args[0][i] != NULL)
		{
			ft_memdel((void **)&args[0][i]);
			if (i + 1 < j)
				args[0][i] = ft_strdup(args[0][i + 1]);
			i++;
		}
	}
	return (env);
}

static int		execute(t_ms *ms, char **env, int i)
{
	int		j;
	char	**args;
	char	**env_used;

	j = 0;
	ft_replacechar(ms->cmd[i], '\t', ' ');
	args = ft_strsplit(ms->cmd[i], ' ');
	env_used = select_env(&args, env);
	if (args[0] && ft_strcmp(args[0], "exit") == 0)
	{
		while (args[j])
			ft_memdel((void **)&args[j++]);
		ft_memdel((void **)&args);
		return (1);
	}
	else
		get_cmd(args, env_used, ms);
	while (args[j])
		ft_memdel((void **)&args[j++]);
	ft_memdel((void **)&args);
	return (0);
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
