/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:53:50 by kbunel            #+#    #+#             */
/*   Updated: 2016/03/22 14:42:50 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_init(t_ps *ps)
{
	ps->opt_v = 0;
	ps->opt_disp = 0;
	ps->opt_command = 0;
	ps->opt_mute_c = 0;
	ps->opt_lc = 0;
	ps->opt_count_arg = 0;
	ps->nb_a = NULL;
	ps->nb_b = NULL;
	ps->last_a = NULL;
	ps->last_b = NULL;
	ps->func = NULL;
	ps->nb_arg = 0;
	ps->nb_comb = 0;
	ps->i = 0;
	ps->f_sa = 0;
	ps->f_sb = 0;
	ps->f_ss = 0;
	ps->f_ra = 0;
	ps->f_rb = 0;
	ps->f_rr = 0;
	ps->f_rra = 0;
	ps->f_rrb = 0;
	ps->f_rrr = 0;
	ps->f_pa = 0;
	ps->f_pb = 0;
}
