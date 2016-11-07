/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 20:33:07 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/29 19:23:25 by kbunel           ###   ########.fr       */
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

void			ft_get_line(char **env, t_ms *ms)
{
	char		*line;
	char 		**args;
	int			i;
	int			j;
	char		*cmd;

	ft_putstr(ms->prompt);
	while (get_next_line(1, &line))
	{
		cmd = get_cmds(line);
		ft_printf("[%s]\n", cmd);
		get_commands(cmd, ms);
		i = 0;
		while (ms->cmd[i])
		{
			ft_printf("{blue}[%s]{eoc}\n", ms->cmd[i]);
			j = 0;
			args = ft_get_args(ms->cmd[i]);
			while (args[j])
				ft_printf("{yellow}[%s]{eoc}\n", args[j++]);
			j = 0;
			if (ft_strcmp(args[0], "exit") == 0)
				exit(EXIT_SUCCESS);
			else
				get_cmd(args, env, ms);
			while (args[j])
				ft_memdel((void **)&args[j++]);
			ft_memdel((void **)&args);
			ft_memdel((void **)&ms->cmd[i++]);
		}
		ft_memdel((void **)&ms->cmd);
		ft_memdel((void **)&cmd);
		ms->cmd = NULL;
		ft_printf(ms->prompt);
		free(line);
	}
}
