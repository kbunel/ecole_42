/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_length_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 23:14:29 by kbunel            #+#    #+#             */
/*   Updated: 2016/03/13 20:03:04 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static long long	ft_len(long long n)
{
	int	i;

	i = 1;
	while (n >= 2)
	{
		i++;
		n >>= 1;
	}
	return (i);
}

char				*ft_itoa_printf_bin_j(uintmax_t n)
{
	long long		i;
	char			*str;

	i = ft_len(n);
	str = ft_strnew(i);
	if (str)
	{
		while (i > 0)
		{
			str[--i] = (n & 1) + 48;
			n >>= 1;
		}
		return (str);
	}
	else
		return (NULL);
}

char				*ft_itoa_printf_bin(long long n, t_printf *conv)
{
	long long				i;
	unsigned long long		k;
	char					*str;

	if ((unsigned long long)n > 9223372036854775807)
		return (ft_itoa_printf_bin_j((uintmax_t)n));
	k = (n >= 0 ? n : n * -1);
	i = (n >= 0 ? ft_len(n) : ft_len(n * -1));
	str = ft_strnew(i);
	if (str)
	{
		while (i > 0)
		{
			str[--i] = (k & 1) + 48;
			k >>= 1;
		}
		if (n < 0)
			conv->nb_sign = '-';
		return (str);
	}
	else
		return (NULL);
}

char				*ft_get_length_b(t_printf *conv, void *ap)
{
	if (conv->length != NULL)
	{
		if (ft_strcmp(conv->length, "hh") == 0)
			return (ft_itoa_printf_bin((unsigned char)ap, conv));
		else if (ft_strcmp(conv->length, "h") == 0)
			return (ft_itoa_printf_bin((unsigned short)ap, conv));
		else if (ft_strcmp(conv->length, "l") == 0)
			return (ft_itoa_printf_bin((unsigned long)ap, conv));
		else if (ft_strcmp(conv->length, "ll") == 0)
			return (ft_itoa_printf_bin((unsigned long long)ap, conv));
		else if (ft_strcmp(conv->length, "j") == 0)
			return (ft_itoa_printf_bin_j((uintmax_t)ap));
		else if (ft_strcmp(conv->length, "z") == 0)
			return (ft_itoa_printf_bin((size_t)ap, conv));
	}
	else
		return (ft_itoa_printf_bin((unsigned)ap, conv));
	return (NULL);
}
