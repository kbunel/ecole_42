/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 19:17:24 by kbunel            #+#    #+#             */
/*   Updated: 2016/03/23 11:47:54 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps			ft_ia_else(t_ps ps)
{
	int		i;
	t_modif	*modif;

	i = 0;
	if (ps.nb_b != NULL)
	{
		modif = (t_modif *)malloc(sizeof(t_modif));
		modif->first = ps.nb_b;
		i = modif->first->nb;
		while (modif->first->next != NULL)
		{
			if (i < modif->first->next->nb)
			{
				i = modif->first->next->nb;
				break ;
			}
			modif->first = modif->first->next;
		}
		while (ps.nb_b->nb != i && ft_f(RB, &ps) == 1)
			ps = ft_add_function(ps, RB);
		if (ft_f(PA, &ps) == 1)
			ps = ft_add_function(ps, PA);
		free(modif);
	}
	return (ps);
}

static t_ps		ft_inverse_last(t_ps ps)
{
	if (ft_f(RRA, &ps) == 1)
		ps = ft_add_function(ps, RRA);
	if (ft_f(RRA, &ps) == 1)
		ps = ft_add_function(ps, RRA);
	if (ft_f(SA, &ps) == 1)
		ps = ft_add_function(ps, SA);
	if (ft_f(RA, &ps) == 1)
		ps = ft_add_function(ps, RA);
	if (ft_f(RA, &ps) == 1)
		ps = ft_add_function(ps, RA);
	return (ps);
}

static t_ps		ft_get_it_1(t_ps ps)
{
	if (ft_multi_check(ps, 0) == 1 && ft_f(RR, &ps) == 2)
		return (ft_add_function(ps, RR));
	else if (ft_check_fwl_b(ps) == 1 && ft_f(RB, &ps) == 1)
		return (ft_add_function(ps, RB));
	else if (ft_check_fwl_a(ps) == 1 && ft_f(RA, &ps) == 1)
		return (ft_add_function(ps, RA));
	else if (ft_multi_check(ps, 1) == 1 && ft_f(RRR, &ps) == 2)
		return (ft_add_function(ps, RRR));
	else if (ft_check_lwf_b(ps) == 1 && ft_f(RRB, &ps) == 1)
		return (ft_add_function(ps, RRB));
	else if (ft_check_lwf_a(ps) == 1 && ft_f(RRA, &ps) == 1)
		return (ft_add_function(ps, RRA));
	else
		return (ps);
}

static t_ps		ft_get_it_2(t_ps ps)
{
	if (ft_multi_check(ps, 2) == 1 && ft_f(SS, &ps) == 2)
		return (ft_add_function(ps, SS));
	else if (ft_check_first_b(ps.nb_b) == 1 && ft_f(SB, &ps) == 1)
		return (ft_add_function(ps, SB));
	else if (ft_check_first_a(ps.nb_a) == 1 && ft_f(SA, &ps) == 1)
		return (ft_add_function(ps, SA));
	else if (ps.nb_a != NULL && ft_check_inverse(ps) == 1)
		return (ft_inverse_last(ps));
	else if (ps.nb_a != NULL && ft_check_last_gn(ps.last_a->nb, ps.nb_a) > 0
				&& ft_f(PB, &ps) == 1)
		return (ft_add_function(ps, PB));
	else
		return (ft_ia_else(ps));
}

t_ps			ft_ia(t_ps ps)
{
	while (ft_check_order(ps) != 1)
	{
		ps = ft_get_it_1(ps);
		ps = ft_get_it_2(ps);
	}
	ps.i--;
	return (ps);
}
