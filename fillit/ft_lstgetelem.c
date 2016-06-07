/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgetelem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 16:33:06 by kbunel            #+#    #+#             */
/*   Updated: 2015/12/18 00:55:11 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_fillit.h"

t_list		*ft_replace_it(t_list *tetris)
{
	int		i;
	int		x_min;
	int		y_min;

	i = 2;
	x_min = tetris->cc[0];
	y_min = tetris->cc[1];
	while (i <= 6)
	{
		if (x_min > tetris->cc[i])
			x_min = tetris->cc[i];
		if (y_min > tetris->cc[i + 1])
			y_min = tetris->cc[i + 1];
		i += 2;
	}
	i = 0;
	while (i <= 7)
	{
		if (i % 2 == 0)
			tetris->cc[i] = tetris->cc[i] - x_min;
		else if (i % 2 != 0)
			tetris->cc[i] = tetris->cc[i] - y_min;
		i++;
	}
	return (tetris);
}

t_list		*ft_add_tetrim(t_list *tetris)
{
	t_list	*new_tetris;

	if ((new_tetris = (t_list *)malloc(sizeof(t_list))))
	{
		if (tetris != NULL)
			new_tetris->p = tetris->p + 1;
		else
			new_tetris->p = 'A';
		new_tetris->next = tetris;
		if (tetris != NULL)
			tetris->prev = new_tetris;
	}
	return (new_tetris);
}

void		ft_add_cc(t_list *tetris, int i, int x, int y)
{
	tetris->cc[i] = x;
	tetris->cc[i + 1] = y;
}

t_list		*ft_null_it(t_list *tetris)
{
	t_list		*init_t;

	init_t = NULL;
	tetris->prev = init_t;
	return (tetris);
}

t_list		*ft_lstgetelem(char **elem, int nb, t_list *tetris)
{
	int		i;
	int		j;
	int		n;

	n = 0;
	while (n < nb)
	{
		i = 0;
		j = 0;
		tetris = ft_add_tetrim(tetris);
		while (elem[n][i] != '\0')
		{
			if (elem[n][i] == tetris->p)
			{
				tetris->cc[j] = (int)malloc(sizeof(int));
				tetris->cc[j + 1] = (int)malloc(sizeof(int));
				ft_add_cc(tetris, j, i % 5, i / 5);
				j += 2;
			}
			i++;
		}
		tetris = ft_replace_it(tetris);
		n++;
	}
	return (ft_null_it(tetris));
}
