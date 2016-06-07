/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_printf_octal_j.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 23:13:48 by kbunel            #+#    #+#             */
/*   Updated: 2016/03/23 16:09:58 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

static long long	ft_len(uintmax_t n)
{
	int	i;

	i = 1;
	while (n >= 8)
	{
		i++;
		n >>= 3;
	}
	return (i);
}

char				*ft_itoa_printf_octal_j(uintmax_t n)
{
	long long		i;
	char			*str;

	i = ft_len(n);
	str = ft_strnew(i);
	if (str)
	{
		while (i > 0)
		{
			str[--i] = (n & 7) + 48;
			n >>= 3;
		}
		return (str);
	}
	else
		return (NULL);
}
