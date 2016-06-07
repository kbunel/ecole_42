/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa_pb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 12:31:45 by kbunel            #+#    #+#             */
/*   Updated: 2016/03/22 19:05:53 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			ft_ps_nb_b_not_null(t_modif *modif, t_ps *ps)
{
	if (ps->nb_a == NULL)
	{
		ps->nb_a = modif->first;
		ps->last_a = ps->nb_a;
		modif->first->next = NULL;
	}
	else if ((modif->first->next = ps->nb_a))
	{
		ps->nb_a->prev = modif->first;
		ps->nb_a = modif->first;
	}
}

static void			ft_ps_nb_a_not_null(t_modif *modif, t_ps *ps)
{
	if (ps->nb_b == NULL)
	{
		ps->nb_b = modif->first;
		ps->last_b = ps->nb_b;
		modif->first->next = NULL;
	}
	else if ((modif->first->next = ps->nb_b))
	{
		ps->nb_b->prev = modif->first;
		ps->nb_b = modif->first;
	}
}

int					ft_pa(t_ps *ps)
{
	t_modif		*modif;

	if (ps->nb_b != NULL && ft_check_pile(ps->nb_b) > 0)
	{
		if (!(modif = (t_modif *)malloc(sizeof(t_modif))))
			ft_error(3);
		modif->first = ps->nb_b;
		if (ps->nb_b->next != NULL)
		{
			modif->second = ps->nb_b->next;
			modif->second->prev = NULL;
			ps->nb_b = modif->second;
		}
		else
		{
			ps->nb_b = NULL;
			ps->last_b = NULL;
		}
		modif->first->prev = NULL;
		ft_ps_nb_b_not_null(modif, ps);
		free(modif);
		return (1);
	}
	return (0);
}

int					ft_pb(t_ps *ps)
{
	t_modif		*modif;

	if (ps->nb_a != NULL && ft_check_pile(ps->nb_a) > 0)
	{
		modif = (t_modif *)malloc(sizeof(t_modif));
		modif->first = ps->nb_a;
		if (ps->nb_a->next != NULL)
		{
			modif->second = ps->nb_a->next;
			modif->second->prev = NULL;
			ps->nb_a = modif->second;
		}
		else
		{
			ps->nb_a = NULL;
			ps->last_a = NULL;
		}
		modif->first->prev = NULL;
		ft_ps_nb_a_not_null(modif, ps);
		free(modif);
		return (1);
	}
	return (0);
}
