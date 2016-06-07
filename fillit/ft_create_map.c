/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 16:24:01 by kbunel            #+#    #+#             */
/*   Updated: 2015/12/18 17:46:31 by tgerboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_fillit.h"

char	*ft_create_map(int len)
{
	char	*map;
	int		j;
	int		k;

	j = 0;
	k = 0;
	if (!(map = ft_memalloc(sizeof(map) * len * len + len)))
		return (NULL);
	ft_memset(map, 46, len * len + len);
	while (map[j] != '\0')
	{
		if (k == len)
		{
			map[j++] = '\n';
			k = 0;
		}
		else
		{
			map[j++] = '.';
			k++;
		}
	}
	return (map);
}
