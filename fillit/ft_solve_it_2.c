/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_it.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 18:48:23 by kbunel            #+#    #+#             */
/*   Updated: 2015/12/18 16:55:52 by tgerboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_fillit.h"

int		ft_place(t_list *tetris, char *map, int j, int i)
{
	int		l;

	l = 0;
	if (j > 6)
		return (1);
	while (map[l] != '\n')
		l++;
	if (map[i + tetris->cc[j] + tetris->cc[j + 1] * (l + 1)] == '.')
		return (ft_place(tetris, map, j + 2, i));
	else
		return (0);
}

char	*ft_place_map(t_list *tetris, char *map, int j, int i)
{
	int		l;

	l = 0;
	if (j > 6)
		return (map);
	while (map[l] != '\n')
		l++;
	map[i + tetris->cc[j] + tetris->cc[j + 1] * (l + 1)] = tetris->p;
	return (ft_place_map(tetris, map, j + 2, i));
}

char	*ft_del_on_map(char *map, char a)
{
	int		i;

	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] == a)
			map[i] = '.';
		i++;
	}
	return (map);
}

char	*ft_add_to_map(char *map)
{
	int		i;

	i = 0;
	while (map[i] != '\n')
		i++;
	return (ft_create_map(i + 1));
}

char	*ft_solve_it(t_list *tetris, char *map)
{
	int		i;

	i = 0;
	while (map[i] != '\0')
	{
		if (ft_place(tetris, map, 0, i) == 1)
		{
			map = ft_place_map(tetris, map, 0, i);
			if (tetris->prev == NULL)
			{
				ft_putstr(map);
				ft_exit(0);
			}
			if (ft_solve_it(tetris->prev, map) != NULL)
				return (map);
		}
		map = ft_del_on_map(map, tetris->p);
		i++;
	}
	if (tetris->p == 'A')
	{
		map = ft_add_to_map(map);
		ft_solve_it(tetris, map);
	}
	return (NULL);
}
