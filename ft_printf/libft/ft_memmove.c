/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 23:38:57 by kbunel            #+#    #+#             */
/*   Updated: 2015/11/27 20:08:39 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*td;
	char	*ts;
	char	*tmps;

	i = 0;
	tmps = (char *)malloc(sizeof(src) * (len));
	ts = (char *)src;
	while (i < len)
	{
		tmps[i] = ts[i];
		i++;
	}
	td = dst;
	i = 0;
	while (i < len)
	{
		td[i] = tmps[i];
		i++;
	}
	free(tmps);
	return (dst);
}
