/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 12:11:35 by kbunel            #+#    #+#             */
/*   Updated: 2016/03/21 14:16:47 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ft_check_pile(t_pile *p)
{
	int		i;

	i = 0;
	if (p != NULL)
	{
		while (p->next != NULL)
		{
			i++;
			p = p->next;
		}
		i++;
	}
	return (i);
}

static int		ft_ss(t_ps *ps)
{
	int		i;

	i = 0;
	i += ft_sa(ps);
	i += ft_sb(ps);
	return (i);
}

static int		ft_rr(t_ps *ps)
{
	int		i;

	i = 0;
	i += ft_ra(ps);
	i += ft_rb(ps);
	return (i);
}

static int		ft_rrr(t_ps *ps)
{
	int		i;

	i = 0;
	i += ft_rra(ps);
	i += ft_rrb(ps);
	return (i);
}

int				ft_f(int f, t_ps *ps)
{
	if (f == SA)
		return (ft_sa(ps));
	else if (f == SB)
		return (ft_sb(ps));
	else if (f == SS)
		return (ft_ss(ps));
	else if (f == PB)
		return (ft_pb(ps));
	else if (f == PA)
		return (ft_pa(ps));
	else if (f == RA)
		return (ft_ra(ps));
	else if (f == RB)
		return (ft_rb(ps));
	else if (f == RR)
		return (ft_rr(ps));
	else if (f == RRA)
		return (ft_rra(ps));
	else if (f == RRB)
		return (ft_rrb(ps));
	else if (f == RRR)
		return (ft_rrr(ps));
	return (0);
}
