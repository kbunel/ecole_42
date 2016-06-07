/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra_rb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 13:49:21 by kbunel            #+#    #+#             */
/*   Updated: 2016/03/22 19:07:01 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					ft_rb(t_ps *ps)
{
	t_modif			*modif;

	if (ft_check_pile(ps->nb_b) > 1)
	{
		modif = (t_modif *)malloc(sizeof(t_modif));
		modif->first = ps->nb_b;
		modif->second = ps->last_b;
		ps->nb_b = ps->nb_b->next;
		ps->nb_b->prev = NULL;
		modif->second->next = modif->first;
		modif->first->next = NULL;
		ps->last_b = modif->first;
		modif->first->prev = modif->second;
		free(modif);
		return (1);
	}
	return (0);
}

int					ft_ra(t_ps *ps)
{
	t_modif		*modif;

	if (ft_check_pile(ps->nb_a) > 1)
	{
		modif = (t_modif *)malloc(sizeof(t_modif));
		modif->first = ps->nb_a;
		modif->second = ps->last_a;
		ps->nb_a = ps->nb_a->next;
		ps->nb_a->prev = NULL;
		modif->second->next = modif->first;
		modif->first->next = NULL;
		ps->last_a = modif->first;
		modif->first->prev = modif->second;
		free(modif);
		return (1);
	}
	return (0);
}
