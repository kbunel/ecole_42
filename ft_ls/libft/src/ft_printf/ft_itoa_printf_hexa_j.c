/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_printf_hexa_j.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 20:27:22 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/13 15:30:54 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

static long long	ft_len_j(uintmax_t n)
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

static uintmax_t	ft_get_hexa_j(t_printf *conv, uintmax_t k)
{
	uintmax_t		h;

	h = k & 15;
	if (h < 10)
		return (h + 48);
	else if (conv->letter == 'X')
		return (h + 55);
	else if (conv->letter == 'x')
		return (h + 87);
	else
		return (0);
}

char				*ft_itoa_printf_hexa_j(uintmax_t n, t_printf *conv)
{
	long long		i;
	uintmax_t		k;
	char			*str;

	i = ft_len_j(n);
	str = ft_strnew(i);
	k = n;
	if (str)
	{
		while (i > 0)
		{
			str[--i] = ft_get_hexa_j(conv, k);
			k >>= 4;
		}
		return (str);
	}
	else
		return (NULL);
}
