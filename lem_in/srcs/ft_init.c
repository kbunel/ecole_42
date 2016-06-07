/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 23:57:41 by kbunel            #+#    #+#             */
/*   Updated: 2016/03/31 19:12:19 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void		ft_init_lemin(t_lm *lm)
{
	lm->start = -1;
	lm->end = -1;
	lm->r_start = NULL;
	lm->r_end = NULL;
	lm->infos = room;
	lm->room = NULL;
	lm->g_room = NULL;
	lm->g_way = NULL;
	lm->ant = NULL;
	lm->g_ant = NULL;
	lm->map = NULL;
}
