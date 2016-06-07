/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:44:15 by kbunel            #+#    #+#             */
/*   Updated: 2016/03/23 11:44:13 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_ps		ft_get_nb(char *argv, t_ps *ps)
{
	t_pile	*new_nb;
	char	*arg;

	arg = ft_strdup(argv);
	if (ft_check_valid_nb(arg, ps) != 0)
	{
		new_nb = (t_pile *)malloc(sizeof(t_pile));
		new_nb->nb = ft_atoi(argv);
		new_nb->prev = NULL;
		if (ps->nb_a == NULL)
		{
			ps->last_a = new_nb;
			new_nb->next = NULL;
		}
		else
		{
			new_nb->next = ps->nb_a;
			ps->nb_a->prev = new_nb;
		}
		ps->nb_a = new_nb;
	}
	free(arg);
	return (*ps);
}

static int		ft_check_doublons(t_ps ps)
{
	t_modif		*modif;

	modif = (t_modif *)malloc(sizeof(t_modif));
	modif->first = ps.nb_a;
	if (ps.nb_a == NULL)
		ft_error(1);
	else if (ps.nb_a->next == NULL)
		return (1);
	ps.nb_a = ps.nb_a->next;
	while (modif->first->next != NULL)
	{
		while (ps.nb_a->next != NULL)
		{
			if (modif->first->nb == ps.nb_a->nb)
				ft_error(1);
			ps.nb_a = ps.nb_a->next;
		}
		if (modif->first->nb == ps.nb_a->nb)
			ft_error(1);
		ps.nb_a = modif->first->next->next;
		modif->first = modif->first->next;
	}
	free(modif);
	return (1);
}

int				main(int argc, char **argv)
{
	t_ps	ps;
	int		i;

	if (argc == 1)
		ft_error(3);
	i = argc;
	ft_init(&ps);
	while (--i > 0)
		ps = ft_get_nb(argv[i], &ps);
	ft_check_doublons(ps);
	ps.nb_arg = argc - 1 - ps.opt_v;
	ps = ft_ia(ps);
	if (ps.opt_mute_c == 0 && ps.func != NULL)
		ft_disp_cmd(ps, 1, 1);
	else
		ft_putchar('\n');
	if (ps.opt_lc == 1)
		ft_disp_line(ps);
	if (ps.opt_count_arg == 1)
		ft_disp_arg_count(ps);
	while (ps.nb_a->next != NULL && (ps.nb_a = ps.nb_a->next))
		free(ps.nb_a->prev);
	free(ps.nb_a);
	ft_memdel((void **)&ps.func);
}
