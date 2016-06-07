/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_datas.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 18:43:31 by kbunel            #+#    #+#             */
/*   Updated: 2016/03/31 11:23:26 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static int			ft_elements(t_lm lm)
{
	if (lm.r_start == NULL || lm.r_end == NULL || lm.room == NULL
			|| lm.ants == 0)
		return (0);
	else
		return (1);
}

void				ft_check_datas(t_lm lm)
{
	if (ft_elements(lm) == 0)
		ft_error(0);
}
