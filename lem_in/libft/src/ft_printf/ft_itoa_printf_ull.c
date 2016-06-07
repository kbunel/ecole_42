/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_printf_ull.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 15:04:17 by kbunel            #+#    #+#             */
/*   Updated: 2016/03/23 16:09:58 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

static long long	ft_len(unsigned long long n)
{
	int	i;

	i = 1;
	while (n >= 10)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char				*ft_itoa_printf_ull(unsigned long long n)
{
	long long				i;
	char					*str;

	i = ft_len(n);
	str = ft_strnew(i);
	if (str)
	{
		while (i > 0)
		{
			str[--i] = n % 10 + 48;
			n /= 10;
		}
		return (str);
	}
	else
		return (NULL);
}
