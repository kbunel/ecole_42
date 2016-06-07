/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra_rrb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 14:23:31 by kbunel            #+#    #+#             */
/*   Updated: 2016/03/22 19:06:47 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ft_rrb(t_ps *ps)
{
	t_modif		*modif;

	if (ft_check_pile(ps->nb_b) > 1)
	{
		modif = (t_modif *)malloc(sizeof(t_modif));
		modif->first = ps->last_b;
		modif->first->prev->next = NULL;
		ps->last_b = modif->first->prev;
		modif->first->next = ps->nb_b;
		ps->nb_b->prev = modif->first;
		ps->nb_b = modif->first;
		ps->nb_b->prev = NULL;
		free(modif);
		return (1);
	}
	return (0);
}

int				ft_rra(t_ps *ps)
{
	t_modif		*modif;

	if (ft_check_pile(ps->nb_a) > 1)
	{
		modif = (t_modif *)malloc(sizeof(t_modif));
		modif->first = ps->last_a;
		modif->first->prev->next = NULL;
		ps->last_a = modif->first->prev;
		modif->first->next = ps->nb_a;
		ps->nb_a->prev = modif->first;
		ps->nb_a = modif->first;
		ps->nb_a->prev = NULL;
		free(modif);
		return (1);
	}
	return (0);
	return (0);
}
