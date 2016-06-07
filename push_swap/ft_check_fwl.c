/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_fwl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 12:15:50 by kbunel            #+#    #+#             */
/*   Updated: 2016/03/23 11:47:47 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_check_inverse(t_ps ps)
{
	while (ps.nb_a->next != NULL && ps.nb_a->next->nb > ps.nb_a->nb)
		ps.nb_a = ps.nb_a->next;
	if (ps.nb_a->next != NULL && ps.nb_a->next->next == NULL)
		return (1);
	else
		return (0);
}

int			ft_check_fwl_a(t_ps ps)
{
	if (ps.nb_a != NULL && ps.last_a != NULL && ps.nb_a->nb > ps.last_a->nb
			&& ps.nb_a->nb > ps.nb_a->next->nb)
		return (1);
	else
		return (0);
}

int			ft_check_fwl_b(t_ps ps)
{
	if (ps.nb_b != NULL && ps.last_b != NULL && ps.nb_b->nb < ps.last_b->nb
			&& ps.nb_b->nb < ps.nb_b->next->nb)
		return (1);
	else
		return (0);
}

int			ft_multi_check(t_ps ps, int i)
{
	if (i == 0 && ft_check_fwl_a(ps) == 1
			&& ft_check_fwl_b(ps) == 1)
		return (1);
	else if (i == 1 && ft_check_lwf_a(ps) == 1
			&& ft_check_lwf_b(ps) == 1)
		return (1);
	else if (i == 2 && ft_check_first_b(ps.nb_b) == 1
			&& ft_check_first_a(ps.nb_a) == 1)
		return (1);
	else
		return (0);
}
