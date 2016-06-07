/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 14:14:17 by kbunel            #+#    #+#             */
/*   Updated: 2015/12/21 13:09:41 by tgerboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_fillit.h"

int		main(int argc, char **argv)
{
	int		nb;
	char	**elem;
	t_list	*elemls;

	elem = NULL;
	elemls = NULL;
	if (argc != 2)
		ft_putstr("error\n");
	else
	{
		nb = ft_check(argv[1], 0, 1, 1);
		if (nb > 0)
		{
			elem = ft_getelem(argv[1], nb);
			elemls = ft_lstgetelem(elem, nb, elemls);
		}
		else
			ft_exit(1);
		free(elem);
		elem = NULL;
		while (elemls->next != NULL)
			elemls = elemls->next;
		ft_solve_it(elemls, ft_create_map(ft_size_min_map(nb)));
	}
	return (0);
}
