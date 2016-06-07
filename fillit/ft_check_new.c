/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 03:22:37 by kbunel            #+#    #+#             */
/*   Updated: 2015/12/18 16:58:24 by tgerboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_fillit.h"

int		ft_check_i(int i, char c)
{
	if (i < 5 && c != '.' && c != '#')
		return (0);
	else if (i == 5 && c != '\n')
		return (0);
	else
		return (1);
}

int		ft_check(char *tetrim, int l, int nb, int i)
{
	int		fd;
	char	buf[1];

	if ((fd = open(tetrim, O_RDONLY)) < 0)
		ft_exit(2);
	while (read(fd, buf, 1))
	{
		if (l == 4 && buf[0] == '\n' && i == 1)
		{
			nb++;
			l = 0;
		}
		else if (ft_check_i(i, buf[0]) == 0)
			return (0);
		else if (i == 5 && buf[0] == '\n')
		{
			i = 1;
			l++;
		}
		else
			i++;
	}
	if (close(fd) == -1)
		ft_exit(3);
	return (l == 4 ? nb : 0);
}
