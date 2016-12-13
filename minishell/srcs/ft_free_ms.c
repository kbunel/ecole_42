/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:40:29 by kbunel            #+#    #+#             */
/*   Updated: 2016/12/13 23:15:36 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void			ft_free_env(char **env)
{
	int		i;

	i = 0;
	while (env[i])
		ft_memdel((void **)&env[i++]);
	ft_memdel((void **)&env);
}

void			ft_free_ms(t_ms *ms)
{
	int			i;

	i = 0;
	while (ms->path[i])
		ft_memdel((void **)&ms->path[i++]);
	ft_memdel((void **)&ms->path);
	ft_memdel((void **)&ms->pwd);
	ft_memdel((void **)&ms->oldpwd);
	ft_memdel((void **)&ms->prompt);
}
