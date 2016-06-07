/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions_ia.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 19:48:12 by kbunel            #+#    #+#             */
/*   Updated: 2016/03/23 11:33:59 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_check_order(t_ps ps)
{
	if (ps.nb_b != NULL)
		return (0);
	if (ps.nb_a != NULL)
		while (ps.nb_a->next != NULL && ps.nb_a->nb < ps.nb_a->next->nb)
			ps.nb_a = ps.nb_a->next;
	if (ps.nb_a != NULL && ps.nb_a->next == NULL)
		return (1);
	else
		return (0);
}

int			ft_check_first_a(t_pile *nb)
{
	if (nb != NULL && nb->next != NULL && nb->nb > nb->next->nb)
		return (1);
	else
		return (0);
}

int			ft_check_first_b(t_pile *nb)
{
	if (nb != NULL && nb->next != NULL && nb->nb < nb->next->nb)
		return (1);
	else
		return (0);
}

t_ps		ft_get_arg(t_ps ps, int func)
{
	if (func == SA)
		ps.f_sa++;
	else if (func == SB)
		ps.f_sb++;
	else if (func == SS)
		ps.f_ss++;
	else if (func == RA)
		ps.f_ra++;
	else if (func == RB)
		ps.f_rb++;
	else if (func == RR)
		ps.f_rr++;
	else if (func == RRA)
		ps.f_rra++;
	else if (func == RRB)
		ps.f_rrb++;
	else if (func == RRR)
		ps.f_rrr++;
	else if (func == PB)
		ps.f_pb++;
	else if (func == PA)
		ps.f_pa++;
	return (ps);
}

t_ps		ft_add_function(t_ps ps, int func)
{
	if (ps.i == 0)
		if (!(ps.func = ft_memalloc(sizeof(int) * ps.nb_arg * ps.nb_arg)))
			ft_error(4);
	ps.func[ps.i] = func;
	ps.i++;
	ps.nb_comb++;
	if (ps.opt_count_arg == 1)
		ps = ft_get_arg(ps, func);
	if (ps.opt_command == 1)
	{
		ft_disp_cmd(ps, func, 2);
		ft_putchar('\n');
	}
	if (ps.opt_disp == 1)
		ft_disp_line(ps);
	return (ps);
}
