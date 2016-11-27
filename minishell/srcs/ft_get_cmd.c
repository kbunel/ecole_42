/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 16:07:57 by kbunel            #+#    #+#             */
/*   Updated: 2016/11/27 21:03:33 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		ft_get_cmd(char **args, char **env, t_ms *ms)
{
	int		i;
	int		e;
	char	*cmd;
	char	*cmdv;

	i = 0;
	e = -1;
	while (ms->path[i] && e == -1)
	{
		cmd = ft_strjoin(ms->path[i], args[0]);
		e = execve(cmd, args, env);
		ft_memdel((void **)&cmd);
		i++;
	}
	i = 0;
	if (e == -1)
	{
		cmd = ft_strjoin(ms->pwd, "/");
		cmdv = ft_strjoin(cmd, args[0]);
		ft_memdel((void **)&cmd);
		e = execve(cmdv, args, env);
		ft_memdel((void **)&cmdv);
		if (e == -1)
			ft_error_ms(CMDNOTFOUND, args[0]);
	}
}
