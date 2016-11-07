/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 20:33:07 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/30 13:16:41 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void		get_cmd(char **args, char **env, t_ms *ms)
{
	int			status;
	pid_t		pid;

	if (ft_strchr(args[0], '/') != NULL || ft_get_builtin(args, env) == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			ft_get_cmd(args, env, ms);
			exit(1);
		}
		else
			wait(&status);
	}
}

static char		**select_env(char ***args, char **env)
{
	int		i;
	int		j;
	int		e;

	i = 0;
	j = 0;
	while (args[0][j] != NULL)
		j++;
	if (args[0][0] != NULL && ft_strcmp(args[0][0], "env") == 0
			&& args[0][1] != NULL)
	{
		if (args[0][1] != NULL && args[0][1][0] == '-')
		{
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
		else
		{
			while (args[0][i] != NULL)
			{
				ft_memdel((void **)&args[0][i]);
				if (i + 1 < j)
					args[0][i] = ft_strdup(args[0][i + 1]);
				i++;
			}
			return (env);
		}
	}
	else
		return (env);
}

void			ft_get_line(char **env, t_ms *ms)
{
	char		*line;
	char 		**args;
	int			i;
	int			j;
	char		**env_used;

	ft_putstr(ms->prompt);
	while (get_next_line(1, &line))
	{
		i = 0;
		ms->cmd = ft_strsplit(line, ';');
		while (ms->cmd[i])
		{
			j = 0;
			args = ft_strsplit(ms->cmd[i], ' ');
			env_used = select_env(&args, env);
			if (ft_strcmp(args[0], "exit") == 0)
				exit(EXIT_SUCCESS);
			else
				get_cmd(args, env_used, ms);
			while (args[j])
				ft_memdel((void **)&args[j++]);
			ft_memdel((void **)&args);
			ft_memdel((void **)&ms->cmd[i++]);
		}
		ft_memdel((void **)&ms->cmd);
		ms->cmd = NULL;
		ft_printf(ms->prompt);
		free(line);
	}
}