/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid_nb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:46:04 by kbunel            #+#    #+#             */
/*   Updated: 2016/03/22 17:36:04 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_check_option(char *argv, t_ps *ps)
{
	int		i;

	ps->opt_v = 1;
	i = 1;
	while (argv[i] != '\0')
	{
		if (argv[i] == 'v')
			ps->opt_disp = 1;
		else if (argv[i] == 'c')
			ps->opt_command = 1;
		else if (argv[i] == 'm')
			ps->opt_mute_c = 1;
		else if (argv[i] == 'l')
			ps->opt_lc = 1;
		else if (argv[i] == 'a')
			ps->opt_count_arg = 1;
		else
			ft_error(2);
		i++;
	}
	return (0);
}

int				ft_check_valid_nb(char *argv, t_ps *ps)
{
	int		i;

	i = 0;
	if ((argv[0] == '-' || argv[0] == '+') && ft_isdigit(argv[1]) == 1)
		i++;
	while (argv[i] != '\0')
	{
		if (ft_isdigit(argv[i]) == 1)
			i++;
		else if (argv[i] == '-')
			return (ft_check_option(argv, ps));
		else
			ft_error(1);
	}
	ft_atoi_check_ps_err(argv);
	return (1);
}
