/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_true_tetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 03:31:35 by kbunel            #+#    #+#             */
/*   Updated: 2015/12/18 16:56:36 by tgerboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_fillit.h"

int		ft_get_point(char *str, int i, char c)
{
	int		p;

	p = 0;
	if (i > 0)
		if (str[i - 1] == c)
			p++;
	if (i < 20)
		if (str[i + 1] == c)
			p++;
	if (i > 4)
		if (str[i - 5] == c)
			p++;
	if (i < 15)
		if (str[i + 5] == c)
			p++;
	return (p);
}

char	*ft_check_map(char *str)
{
	int		i;
	int		p;
	int		a;
	char	c;

	i = 0;
	p = 0;
	a = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '.' && str[i] != '\n' && str[i] != '\0')
		{
			c = str[i];
			a++;
			p += ft_get_point(str, i, c);
		}
		i++;
	}
	if (p >= 6 && a == 4)
		return (str);
	else
	{
		ft_exit(1);
		return (NULL);
	}
}
