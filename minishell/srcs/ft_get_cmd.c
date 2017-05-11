/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 16:07:57 by kbunel            #+#    #+#             */
/*   Updated: 2017/05/11 17:04:12 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void			ft_exec_from_pwd(char **args, char **env)
{
	char	*pwd;
	char	*cmd;
	char	*cmdv;
	int		e;

	pwd = ft_getenv(env, "PWD");
	cmd = ft_strjoin(pwd, "/");
	cmdv = ft_strjoin(cmd, args[0]);
	e = execve(cmdv, args, env);
	ft_memdel((void **)&cmd);
	ft_memdel((void **)&cmdv);
	ft_memdel((void **)&pwd);
	if (e == -1)
		ft_error_ms(CMDNOTFOUND, args[0]);
}

void				ft_get_cmd(char **args, char **env, t_ms *ms)
{
	int		i;
	int		e;
	char	*cmd;

	i = 0;
	e = -1;
	while (ms->path[i] && e == -1)
	{
		cmd = ft_strjoin(ms->path[i], args[0]);
		e = execve(cmd, args, env);
		ft_memdel((void **)&cmd);
		i++;
	}
	if (e == -1)
		ft_exec_from_pwd(args, env);
}
