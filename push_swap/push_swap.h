/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:48:10 by kbunel            #+#    #+#             */
/*   Updated: 2016/03/23 11:47:36 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

enum					e_func
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}						t_func;

typedef struct			s_pile
{
	int					nb;
	struct s_pile		*prev;
	struct s_pile		*next;
}						t_pile;

typedef struct			s_modif
{
	t_pile				*first;
	t_pile				*second;
	t_pile				*third;
}						t_modif;

typedef struct			s_ps
{
	t_pile				*nb_a;
	t_pile				*nb_b;
	t_pile				*last_a;
	t_pile				*last_b;
	int					*func;
	int					opt_v;
	int					opt_disp;
	int					opt_command;
	int					opt_mute_c;
	int					opt_lc;
	int					opt_count_arg;
	int					nb_arg;
	int					nb_comb;
	int					i;
	int					f_sa;
	int					f_sb;
	int					f_ss;
	int					f_pa;
	int					f_pb;
	int					f_ra;
	int					f_rb;
	int					f_rr;
	int					f_rra;
	int					f_rrb;
	int					f_rrr;
}						t_ps;

void					ft_init(t_ps *ps);
int						ft_check_valid_nb(char *argv, t_ps *ps);
void					ft_error(int error);
void					ft_atoi_check_ps_err(const char *str);
int						ft_sa(t_ps *ps);
int						ft_sb(t_ps *ps);
int						ft_pb(t_ps *ps);
int						ft_pa(t_ps *ps);
int						ft_ra(t_ps *ps);
int						ft_rb(t_ps *ps);
int						ft_rra(t_ps *ps);
int						ft_rrb(t_ps *ps);
int						ft_f(int f, t_ps *ps);
int						ft_check_pile(t_pile *p);
int						ft_check_order(t_ps ps);
int						ft_check_first_a(t_pile *nb);
int						ft_check_first_b(t_pile *nb);
t_ps					ft_add_function(t_ps ps, int func);
t_ps					ft_ia(t_ps ps);
int						ft_check_lwf_a(t_ps ps);
int						ft_check_lwf_b(t_ps ps);
int						ft_check_last_gn(int last, t_pile *nb);
int						ft_a_b_good(t_pile *nb_a, t_pile *nb_b);
int						ft_check_fwl_a(t_ps ps);
int						ft_check_fwl_b(t_ps ps);
int						ft_check_last_ab(t_ps ps);
void					ft_disp_line(t_ps ps);
int						ft_check_a(t_pile *nb);
void					ft_disp_cmd(t_ps ps, int cmd, int i);
void					ft_disp_arg_count(t_ps ps);
int						ft_check_inverse(t_ps ps);
int						ft_multi_check(t_ps ps, int i);

#endif
