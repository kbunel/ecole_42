/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 19:35:35 by kbunel            #+#    #+#             */
/*   Updated: 2016/03/31 21:22:11 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static void			ft_get_ants(t_lm *lm)
{
	int			i;
	t_ant		*new_ant;

	i = 1;
	while (i <= lm->ants)
	{
		new_ant = (t_ant *)malloc(sizeof(t_ant));
		new_ant->name = i;
		new_ant->status = 0;
		new_ant->room = lm->r_start;
		new_ant->next = NULL;
		if (lm->ant == NULL)
			lm->ant = new_ant;
		else
		{
			lm->g_ant = lm->ant;
			while (lm->g_ant->next != NULL)
				lm->g_ant = lm->g_ant->next;
			lm->g_ant->next = new_ant;
		}
		i++;
	}
}

int					ft_check_in_line(t_ant g_ant, t_ant l_ant)
{
	int		i;
	int		d;
	t_ant	*ant;
	t_way	*way;

	i = 0;
	d = 0;
	ant = &l_ant;
	while (ant != NULL)
	{
		if (ant->room == g_ant.room && ant->name < g_ant.name)
			i++;
		ant = ant->next;
	}
	d = g_ant.room->way->rr->dist;
	way = g_ant.room->way;
	while (way != NULL)
	{
		if (way->rr->dist < d && way->rr->dist >= 0)
			d = way->rr->dist;
		way = way->next;
	}
	return (d + i);
}

void				ft_br(t_lm *lm, t_ant g_ant)
{
	lm->g_way = lm->g_ant->room->way;
	while (lm->g_way != NULL)
	{
		if (lm->g_way->valid == 1)
		{
			if ((lm->g_way->rr->ants == 0 && (!(lm->g_room != NULL
				&& lm->g_way->rr->dist > lm->g_room->dist))
				&& lm->g_way->rr->dist >= 0
				&& (!(g_ant.room == lm->r_start
				&& ft_check_in_line(g_ant, *lm->ant) < lm->g_way->rr->dist)))
					|| lm->g_way->rr == lm->r_end)
				lm->g_room = lm->g_way->rr;
		}
		lm->g_way = lm->g_way->next;
	}
}

void				ft_go(t_lm *lm)
{
	ft_putendl(lm->map);
	while (lm->r_end->ants < lm->ants)
	{
		lm->g_ant = lm->ant;
		while (lm->g_ant != NULL)
		{
			if (lm->g_ant->room != lm->r_end)
			{
				lm->g_room = NULL;
				ft_br(lm, *lm->g_ant);
				if (lm->g_room != NULL)
				{
					lm->g_ant->room->ants--;
					lm->g_ant->room = lm->g_room;
					lm->g_room->ants++;
					lm->g_ant->status = 1;
				}
				if (lm->g_ant != NULL && lm->g_ant->status-- == 1)
					ft_printf("L%d-%s ", lm->g_ant->name,
							lm->g_ant->room->name);
			}
			lm->g_ant = lm->g_ant->next;
		}
		ft_putchar('\n');
	}
}

void				ft_get_paths(t_lm *lm)
{
	ft_get_ants(lm);
	lm->g_room = lm->r_end;
	sh_path(*lm, lm->g_room, lm->g_way, 1);
	if (lm->r_start->dist == -1)
		ft_error(0);
	ft_go(lm);
}
