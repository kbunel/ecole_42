/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_w_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 16:53:59 by kbunel            #+#    #+#             */
/*   Updated: 2016/03/23 16:09:58 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

static char				*ft_convert(wchar_t wc, char *str, int i)
{
	if (wc < 128)
		str[i] = ((wc >> 0) & 127) | 0;
	else if (wc < 2048)
	{
		str[i] = ((wc >> 6) & 31) | 192;
		str[i + 1] = ((wc >> 0) & 63) | 128;
	}
	else if (wc < 65536)
	{
		str[i] = ((wc >> 12) & 15) | 224;
		str[i + 1] = ((wc >> 6) & 63) | 128;
		str[i + 2] = ((wc >> 0) & 63) | 128;
	}
	else if (wc < 1114112)
	{
		str[i] = ((wc >> 18) & 7) | 240;
		str[i + 1] = ((wc >> 12) & 63) | 128;
		str[i + 2] = ((wc >> 6) & 63) | 128;
		str[i + 3] = ((wc >> 0) & 63) | 128;
	}
	return (str);
}

static unsigned int		ft_size_bin_wstr(wchar_t *str)
{
	unsigned int		i;
	unsigned int		a;

	i = 0;
	a = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 128)
			a++;
		else if (str[i] < 2048)
			a += 2;
		else if (str[i] < 65536)
			a += 3;
		else if (str[i] < 1114112)
			a += 4;
		i++;
	}
	return (a);
}

static unsigned int		ft_size_bin(wchar_t wc)
{
	unsigned int		a;

	a = 0;
	if (wc < 128)
		a++;
	else if (wc < 2048)
		a += 2;
	else if (wc < 65536)
		a += 3;
	else if (wc < 1114112)
		a += 4;
	return (a);
}

char					*ft_get_w_string(wchar_t *ap, t_printf conv)
{
	char				*str;
	char				*sub;
	unsigned int		i;
	unsigned int		a;

	str = ft_strnew(ft_size_bin_wstr(ap));
	i = 0;
	a = 0;
	while (ap[a] != '\0')
	{
		str = ft_convert(ap[a], str, i);
		i += ft_size_bin(ap[a++]);
	}
	if (conv.precision != NULL
			&& ft_atoi(conv.precision) < (int)ft_strlen(str))
	{
		sub = ft_strsub(str, 0, ft_atoi(conv.precision));
		free(str);
		return (sub);
	}
	else
		return (str);
	return (str);
}
