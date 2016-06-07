/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_lwf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 21:39:36 by kbunel            #+#    #+#             */
/*   Updated: 2016/03/22 13:37:48 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_check_last_ab(t_ps ps)
{
	if (ps.nb_a != NULL && ps.nb_b != NULL)
	{
		while (ps.nb_a->next != NULL)
			ps.nb_a = ps.nb_a->next;
		while (ps.nb_b->next != NULL)
			ps.nb_b = ps.nb_b->next;
		if (ps.nb_b > ps.nb_a)
			return (1);
	}
	return (0);
}

int			ft_check_last_gn(int last, t_pile *nb)
{
	if (nb != NULL)
	{
		while (nb->next != NULL
				&& nb->nb < nb->next->nb)
		{
			nb = nb->next;
		}
		if (nb->nb != last)
			return (1);
	}
	return (0);
}

int			ft_check_lwf_a(t_ps ps)
{
	if (ps.nb_a != NULL && ps.nb_a->next != NULL)
	{
		if (ps.nb_a->nb < ps.nb_a->next->nb)
		{
			if (ps.nb_a->nb > ps.last_a->nb)
				return (1);
		}
	}
	return (0);
}

int			ft_check_lwf_b(t_ps ps)
{
	if (ps.nb_b != NULL && ps.nb_b->next != NULL)
	{
		if (ps.nb_b->nb > ps.nb_b->next->nb)
		{
			if (ps.nb_b->nb < ps.last_b->nb)
				return (1);
		}
	}
	return (0);
}
