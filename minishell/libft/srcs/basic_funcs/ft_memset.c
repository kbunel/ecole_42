/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:12:04 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/13 15:30:54 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*t;

	i = 0;
	t = b;
	while (i < len)
	{
		t[i] = c;
		i++;
	}
	return (b);
}
