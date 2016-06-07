/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_it.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 20:14:42 by kbunel            #+#    #+#             */
/*   Updated: 2016/03/15 22:11:51 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ft_sb_2_args(t_ps *ps)
{
	t_modif		*modif;

	modif = (t_modif *)malloc(sizeof(t_modif));
	modif->first = ps->nb_b->next;
	modif->first->prev = NULL;
	modif->second = ps->nb_b;
	modif->second->prev = modif->first;
	ps->nb_b = modif->first;
	ps->nb_b->next = modif->second;
	ps->nb_b->next->next = NULL;
	free(modif);
	return (1);
}

int				ft_sb(t_ps *ps)
{
	t_modif		*modif;

	if (ft_check_pile(ps->nb_b) == 2)
		return (ft_sb_2_args(ps));
	else if (ft_check_pile(ps->nb_b) >= 2)
	{
		modif = (t_modif *)malloc(sizeof(t_modif));
		modif->first = ps->nb_b->next;
		modif->first->prev = NULL;
		modif->second = ps->nb_b;
		modif->second->prev = modif->first;
		modif->third = ps->nb_b->next->next;
		modif->third->prev = modif->second;
		ps->nb_b = modif->first;
		ps->nb_b->next = modif->second;
		ps->nb_b->next->next = modif->third;
		free(modif);
		return (1);
	}
	else
		return (0);
}

int				ft_sa_2_args(t_ps *ps)
{
	t_modif		*modif;

	modif = (t_modif *)malloc(sizeof(t_modif));
	modif->first = ps->nb_a->next;
	modif->first->prev = NULL;
	modif->second = ps->nb_a;
	modif->second->prev = modif->first;
	ps->nb_a = modif->first;
	ps->nb_a->next = modif->second;
	ps->nb_a->next->next = NULL;
	free(modif);
	return (1);
}

int				ft_sa(t_ps *ps)
{
	t_modif		*modif;

	if (ft_check_pile(ps->nb_a) == 2)
		return (ft_sa_2_args(ps));
	else if (ft_check_pile(ps->nb_a) > 2)
	{
		modif = (t_modif *)malloc(sizeof(t_modif));
		modif->first = ps->nb_a->next;
		modif->first->prev = NULL;
		modif->second = ps->nb_a;
		modif->second->prev = modif->first;
		modif->third = ps->nb_a->next->next;
		modif->third->prev = modif->second;
		ps->nb_a = modif->first;
		ps->nb_a->next = modif->second;
		ps->nb_a->next->next = modif->third;
		free(modif);
		return (1);
	}
	else
		return (0);
}
