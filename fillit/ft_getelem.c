/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getelem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 17:53:18 by kbunel            #+#    #+#             */
/*   Updated: 2015/12/18 16:58:55 by tgerboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_fillit.h"

char	**ft_getelem(char *tetrim, int m)
{
	int		fd;
	char	buf[1];
	int		i;
	char	*tetris;

	i = 0;
	tetris = (char *)ft_memalloc((m * 20 + m) * (sizeof(char)));
	fd = open(tetrim, O_RDONLY);
	if (fd == -1)
		ft_exit(2);
	while (read(fd, buf, 1))
	{
		if ((i + 1) % 21 == 0)
			tetris[i] = '0';
		else if (buf[0] == '#')
			tetris[i] = 65 + (i / 21);
		else
			tetris[i] = buf[0];
		i++;
	}
	tetris[i] = '\0';
	if (close(fd) == -1)
		ft_exit(3);
	return (ft_strsplit(tetris, '0'));
}
