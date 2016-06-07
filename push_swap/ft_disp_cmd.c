/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 14:25:23 by kbunel            #+#    #+#             */
/*   Updated: 2016/03/22 18:28:45 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_cmd(int cmd)
{
	if (cmd == SA)
		ft_putstr("sa");
	else if (cmd == SB)
		ft_putstr("sb");
	else if (cmd == SS)
		ft_putstr("ss");
	else if (cmd == RA)
		ft_putstr("ra");
	else if (cmd == RB)
		ft_putstr("rb");
	else if (cmd == RR)
		ft_putstr("rr");
	else if (cmd == RRA)
		ft_putstr("rra");
	else if (cmd == RRB)
		ft_putstr("rrb");
	else if (cmd == RRR)
		ft_putstr("rrr");
	else if (cmd == 3)
		ft_putstr("pa");
	else if (cmd == PB)
		ft_putstr("pb");
}

void			ft_disp_cmd(t_ps ps, int cmd, int i)
{
	int		j;

	j = 0;
	if (i == 1)
	{
		while (j <= ps.i)
		{
			ft_cmd(ps.func[j]);
			if (j++ < ps.i)
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
	else if (i == 2)
		ft_cmd(cmd);
}
