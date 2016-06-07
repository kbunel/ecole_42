/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_new_way.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 19:21:26 by kbunel            #+#    #+#             */
/*   Updated: 2016/03/31 19:29:00 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void		ft_check_new_way(t_way *new_way, t_way *new_way_2)
{
	if (new_way->lr == NULL || new_way->rr == NULL)
		new_way->valid = 0;
	else
		new_way->valid = 1;
	if (new_way_2->lr == NULL || new_way_2->rr == NULL)
		new_way_2->valid = 0;
	else
		new_way_2->valid = 1;
}
