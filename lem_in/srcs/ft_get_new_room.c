/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_new_room.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 23:59:28 by kbunel            #+#    #+#             */
/*   Updated: 2016/03/31 19:28:11 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static int			ft_get_cc(char *line, int ccp)
{
	int		i;
	int		j;
	int		a;
	char	*cc;
	int		c;

	a = 0;
	j = 0;
	i = 0;
	while (j <= ccp)
	{
		while (ft_isdigit(line[i]) == 1)
			i++;
		if (j++ == ccp)
			cc = ft_strsub(line, a, i - a);
		a = ++i;
	}
	c = ft_atoi(cc);
	free(cc);
	return (c);
}

static void			ft_gnr(t_lm *lm, t_room *new_room, int kind)
{
	if (lm->room != NULL)
	{
		lm->g_room = lm->room;
		while (lm->g_room->next != NULL)
			lm->g_room = lm->g_room->next;
		lm->g_room->next = new_room;
	}
	else
		lm->room = new_room;
	if (kind == start)
	{
		new_room->ants = lm->ants;
		lm->r_start = new_room;
	}
	else if (kind == end)
	{
		new_room->dist = 0;
		lm->r_end = new_room;
	}
}

int					ft_get_new_room(char *line, t_lm *lm, int kind)
{
	t_room		*new_room;

	if (ft_check_room(line, lm, room) == 0)
		return (0);
	if (!(new_room = (t_room *)malloc(sizeof(t_room))))
		ft_error(4);
	new_room->name = ft_get_name(line, room, 0);
	new_room->x = ft_get_cc(line, 1);
	new_room->y = ft_get_cc(line, 2);
	new_room->nb_way = 0;
	new_room->dist = -1;
	new_room->ants = 0;
	new_room->way = NULL;
	new_room->next = NULL;
	ft_gnr(lm, new_room, kind);
	return (1);
}

static t_room		*ft_grc(t_lm *lm, char *name, int i)
{
	t_way		*new_way;

	new_way = lm->g_way;
	lm->g_room = lm->room;
	while (lm->g_room != NULL)
		if (ft_strcmp(lm->g_room->name, name) == 0)
			break ;
		else
			lm->g_room = lm->g_room->next;
	if (lm->g_room != NULL && ft_strcmp(lm->g_room->name, name) == 0 && i == 0)
	{
		lm->g_room->nb_way++;
		if (lm->g_room->way != NULL)
		{
			lm->g_way = lm->g_room->way;
			while (lm->g_way->next != NULL)
				lm->g_way = lm->g_way->next;
			lm->g_way->next = new_way;
		}
		else
			lm->g_room->way = new_way;
	}
	if (lm->g_room != NULL && ft_strcmp(lm->g_room->name, name) != 0)
		return (NULL);
	return (lm->g_room);
}

int					ft_get_new_way(char *line, t_lm *lm)
{
	t_way		*new_way;
	t_way		*new_way_2;
	char		*lr;
	char		*rr;

	lr = ft_get_name(line, way, 0);
	rr = ft_get_name(line, way, 1);
	if (ft_strcmp(lr, rr) == 0)
		return (0);
	if (!(new_way = (t_way *)malloc(sizeof(t_way))))
		ft_error(4);
	new_way->next = NULL;
	lm->g_way = new_way;
	new_way->lr = ft_grc(lm, lr, 0);
	new_way->rr = ft_grc(lm, rr, 1);
	if (!(new_way_2 = (t_way *)malloc(sizeof(t_way))))
		ft_error(4);
	new_way_2->next = NULL;
	lm->g_way = new_way_2;
	new_way_2->lr = ft_grc(lm, rr, 0);
	new_way_2->rr = ft_grc(lm, lr, 1);
	ft_check_new_way(new_way, new_way_2);
	ft_memdel((void **)&rr);
	ft_memdel((void **)&lr);
	return (1);
}
