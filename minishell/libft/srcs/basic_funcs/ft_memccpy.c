/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:10:15 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/13 15:30:54 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*td;
	char	*ts;

	i = 0;
	td = dst;
	ts = (char *)src;
	while (ts[i] != '\0' && i < n)
	{
		td[i] = ts[i];
		if (ts[i] == c)
			return (&td[i + 1]);
		i++;
	}
	if (ts[i] == c)
		return (&td[i + 1]);
	td[i] = '\0';
	return (NULL);
}
