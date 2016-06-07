/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 14:14:03 by kbunel            #+#    #+#             */
/*   Updated: 2016/03/22 19:07:35 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_ps		ft_get_a_b(t_ps ps)
{
	if (ps.nb_a != NULL)
		while (ps.nb_a->next != NULL)
			ps.nb_a = ps.nb_a->next;
	if (ps.nb_b != NULL)
		while (ps.nb_b->next != NULL)
			ps.nb_b = ps.nb_b->next;
	return (ps);
}

static void		ft_nb_comb(int comb)
{
	ft_putendl("\033[0m\n--------------------------------------");
	ft_putstr("Nombre de combinaisons: ");
	ft_putnbr(comb);
	ft_putendl("\n--------------------------------------");
}

void			ft_disp_line(t_ps ps)
{
	ps = ft_get_a_b(ps);
	ft_putstr("Pile a: ");
	if (ps.nb_a != NULL)
	{
		while (ps.nb_a->prev != NULL)
		{
			ft_putnbr(ps.nb_a->nb);
			ft_putchar(' ');
			ps.nb_a = ps.nb_a->prev;
		}
		ft_putnbr(ps.nb_a->nb);
	}
	ft_putstr("\033[31m\nPile b: ");
	if (ps.nb_b != NULL)
	{
		while (ps.nb_b->prev != NULL)
		{
			ft_putnbr(ps.nb_b->nb);
			ft_putchar(' ');
			ps.nb_b = ps.nb_b->prev;
		}
		ft_putnbr(ps.nb_b->nb);
		ft_putchar('\n');
	}
	ft_nb_comb(ps.nb_comb);
}
