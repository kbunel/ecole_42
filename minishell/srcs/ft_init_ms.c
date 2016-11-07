/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:09:43 by kbunel            #+#    #+#             */
/*   Updated: 2016/10/04 22:01:01 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		ft_init_ms(t_ms *ms)
{
	ms->path = NULL;
	ms->pwd = NULL;
	ms->oldpwd = NULL;
	ms->cmd = NULL;
	ms->prompt = ft_strdup("$> ");
}
