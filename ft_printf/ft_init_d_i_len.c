/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 16:25:01 by kbunel            #+#    #+#             */
/*   Updated: 2016/03/10 22:23:09 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_init_d_i_len(t_printf conv, char *print)
{
	int		i;

	i = (print != NULL) ? ft_strlen(print) : 0;
	i = (conv.mfw != NULL && ft_atoi(conv.mfw) > i) ? ft_atoi(conv.mfw) + 1 : i;
	i += (conv.nb_sign == '-') ? 1 : 0;
	i += (ft_strichr(conv.flag, 0, ' ') >= 0
			|| ft_strichr(conv.flag, 0, '+')) ? 1 : 0;
	i += (ft_strichr(conv.flag, 0, '#') >= 0
			&& (conv.letter == 'x' || conv.letter == 'X')) ? 2 : 0;
	i += (ft_strichr(conv.flag, 0, '#') >= 0 && conv.letter == 'o') ? 1 : 0;
	i = (conv.precision != NULL
	&& ft_atoi(conv.precision) > i) ? ft_atoi(conv.precision) + 1 : i;
	return (i);
}

int		ft_init_d_i_string(t_printf conv, char *print)
{
	int		i;

	i = ft_strlen(print);
	i = (conv.mfw != NULL && ft_atoi(conv.mfw) > i) ? ft_atoi(conv.mfw) + 1 : i;
	return (i);
}
