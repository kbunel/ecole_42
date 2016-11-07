/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 00:22:27 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/13 15:30:54 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*a;
	char	*b;
	int		c;
	int		d;

	i = 0;
	a = (char *)s1;
	b = (char *)s2;
	while (i < n)
	{
		if (a[i] == b[i])
			i++;
		else
		{
			c = ((unsigned char)a[i]);
			d = ((unsigned char)b[i]);
			return (c - d);
		}
	}
	return (0);
}
