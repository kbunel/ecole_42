/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 20:57:43 by kbunel            #+#    #+#             */
/*   Updated: 2016/03/31 20:56:09 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static	int		ft_len(int n)
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

char			*ft_itoa(int n)
{
	int		i;
	int		k;
	char	*str;

	if (n == -2147483648)
		return ("-2147483648");
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
