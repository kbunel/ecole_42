/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 13:03:42 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/13 15:30:54 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = ft_strlen(dst);
	k = ft_strlen(dst);
	if (size >= j)
	{
		while (src[i] != '\0' && j + 1 < size)
		{
			dst[j++] = (char)src[i++];
		}
		dst[j] = '\0';
		return (k + ft_strlen(src));
	}
	return (ft_strlen(src) + size);
}
