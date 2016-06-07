/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_arg_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 14:47:19 by kbunel            #+#    #+#             */
/*   Updated: 2016/03/23 12:05:07 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_disp_arg_count(t_ps ps)
{
	ft_putstr("SA  : ");
	ft_putnbr(ps.f_sa);
	ft_putstr("\nSB  : ");
	ft_putnbr(ps.f_sb);
	ft_putstr("\nSS  : ");
	ft_putnbr(ps.f_ss);
	ft_putstr("\nRA  : ");
	ft_putnbr(ps.f_ra);
	ft_putstr("\nRB  : ");
	ft_putnbr(ps.f_rb);
	ft_putstr("\nRR  : ");
	ft_putnbr(ps.f_rr);
	ft_putstr("\nRRA : ");
	ft_putnbr(ps.f_rra);
	ft_putstr("\nRRB : ");
	ft_putnbr(ps.f_rrb);
	ft_putstr("\nRRR : ");
	ft_putnbr(ps.f_rrr);
	ft_putstr("\nPA  : ");
	ft_putnbr(ps.f_pa);
	ft_putstr("\nPB  : ");
	ft_putnbr(ps.f_pb);
	ft_putchar('\n');
}
