/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:09:43 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/29 14:47:38 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		ft_init_ms(t_ms *ms, int argc, char **argv)
{
	(void)argc;
	(void)argv;
	ms->path = NULL;
	ms->pwd = NULL;
	ms->oldpwd = NULL;
	ms->cmd = NULL;
	ms->prompt = ft_strdup("$> ");
}
