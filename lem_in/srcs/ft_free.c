/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 17:34:48 by kbunel            #+#    #+#             */
/*   Updated: 2016/03/31 19:08:32 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void		ft_free(t_lm *lm)
{
	ft_memdel((void **)&lm->map);
	while (lm->ant != NULL)
	{
		lm->g_ant = lm->ant;
		lm->ant = lm->g_ant->next;
		ft_memdel((void **)&lm->g_ant);
	}
	while (lm->room != NULL)
	{
		lm->g_room = lm->room;
		while (lm->room->way != NULL)
		{
			lm->g_way = lm->room->way;
			lm->room->way = lm->g_way->next;
			ft_memdel((void **)&lm->g_way);
		}
		lm->room = lm->room->next;
		ft_memdel((void **)&lm->g_room->name);
		ft_memdel((void **)&lm->g_room);
	}
	ft_memdel((void **)&lm->g_ant);
	ft_memdel((void **)&lm->g_room);
	ft_memdel((void **)&lm->g_way);
}
