/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 21:44:10 by kbunel            #+#    #+#             */
/*   Updated: 2015/12/01 15:35:03 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*td;
	char	*ts;

	i = 0;
	td = dst;
	ts = (char *)src;
	while (i < n)
	{
		td[i] = ts[i];
		i++;
	}
	return (dst);
}
