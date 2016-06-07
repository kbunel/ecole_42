/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 19:23:03 by kbunel            #+#    #+#             */
/*   Updated: 2016/03/31 19:24:50 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void				sh_path(t_lm lm, t_room *g_room, t_way *g_way, int i)
{
	g_way = g_room->way;
	while (g_way != NULL && g_way->lr != lm.r_start)
	{
		if (g_way->rr != NULL && g_way->valid == 1 && (g_way->rr->dist == -1
					|| g_way->rr->dist > i + 1))
		{
			g_way->rr->dist = i;
			sh_path(lm, g_way->rr, g_way, i + 1);
		}
		g_way = g_way->next;
	}
}
