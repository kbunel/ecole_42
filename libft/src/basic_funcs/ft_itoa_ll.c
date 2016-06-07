/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 14:02:02 by kbunel            #+#    #+#             */
/*   Updated: 2016/03/23 16:05:59 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static	int		ft_len(long long n)
{
	size_t	i;

	i = 1;
	while (n >= 10)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char			*ft_itoa_ll(long long n)
{
	int		i;
	int		k;
	char	*str;

	i = (n >= 0 ? ft_len(n) : ft_len(n * -1) + 1);
	str = (n >= 0 ? ft_strnew(i) : ft_strnew(i));
	k = (n >= 0 ? n : n * -1);
	if (str)
	{
		while (i > 0)
		{
			str[--i] = k % 10 + 48;
			k /= 10;
		}
		if (n < 0)
			str[i] = '-';
		return (str);
	}
	else
		return (NULL);
}
