/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_printf_octal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:57:16 by kbunel            #+#    #+#             */
/*   Updated: 2016/03/23 16:09:58 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

static long long	ft_len(long long n)
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

static char			*ft_get_length_up(unsigned long long n, t_printf *conv)
{
	conv->length = ft_strdup("j");
	return (ft_get_length(conv, (void *)n));
}

char				*ft_itoa_printf_octal(long long n, t_printf *conv)
{
	long long				i;
	unsigned long long		k;
	char					*str;

	if ((unsigned long long)n > 9223372036854775807)
		return (ft_get_length_up((unsigned long long)n, conv));
	k = (n >= 0 ? n : n * -1);
	i = (n >= 0 ? ft_len(n) : ft_len(n * -1));
	str = ft_strnew(i);
	if (str)
	{
		while (i > 0)
		{
			str[--i] = (k & 7) + 48;
			k >>= 3;
		}
		if (n < 0)
			conv->nb_sign = '-';
		return (str);
	}
	else
		return (NULL);
}
