/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_printf_hexa.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 16:00:18 by kbunel            #+#    #+#             */
/*   Updated: 2016/03/23 16:09:58 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

static long long	ft_len(unsigned long long n)
{
	int	i;

	i = 1;
	while (n >= 16)
	{
		i++;
		n >>= 4;
	}
	return (i);
}

static long long	ft_get_hexa(t_printf *conv, unsigned long long k)
{
	unsigned long long		h;

	h = k & 15;
	if (h < 10)
		return (h + 48);
	else if (conv->letter == 'X')
		return (h + 55);
	else if (conv->letter == 'x' || conv->letter == 'p')
		return (h + 87);
	else
		return (0);
}

static char			*ft_get_length_up(unsigned long long n, t_printf *conv)
{
	conv->length = ft_strdup("j");
	return (ft_get_length(conv, (void *)n));
}

char				*ft_itoa_printf_hexa(long long n, t_printf *conv)
{
	long long				i;
	unsigned long long		k;
	char					*str;

	if ((unsigned long long)n > 9223372036854775807)
		return (ft_get_length_up((unsigned long long)n, conv));
	i = (n >= 0 ? ft_len(n) : ft_len(n * -1));
	str = ft_strnew(i);
	k = (n >= 0 ? n : n * -1);
	if (str)
	{
		while (i > 0)
		{
			str[--i] = ft_get_hexa(conv, k);
			k >>= 4;
		}
		if (n < 0)
			conv->nb_sign = '-';
		return (str);
	}
	else
		return (NULL);
}
