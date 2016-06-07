/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 12:06:36 by kbunel            #+#    #+#             */
/*   Updated: 2016/03/11 22:02:30 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static long long	ft_len(long long n)
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

char				*ft_itoa_printf(long long n, t_printf *conv)
{
	long long				i;
	unsigned long long		k;
	char					*str;

	i = (n >= 0 ? ft_len(n) : ft_len(n * -1));
	if (n < 0)
		conv->nb_sign = '-';
	k = (n >= 0 ? n : n * -1);
	if (k > 9223372036854775807)
		return (ft_strdup("9223372036854775808"));
	str = ft_strnew(i);
	if (str)
	{
		while (i > 0)
		{
			str[--i] = k % 10 + 48;
			k /= 10;
		}
		return (str);
	}
	else
		return (NULL);
}
