/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_wchar_t.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 12:47:34 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/13 15:30:54 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

static char		*ft_convert(wchar_t wc, char *str)
{
	if (wc < 128)
		str[0] = ((wc >> 0) & 127) | 0;
	else if (wc < 2048)
	{
		str[0] = ((wc >> 6) & 31) | 192;
		str[1] = ((wc >> 0) & 63) | 128;
	}
	else if (wc < 65536)
	{
		str[0] = ((wc >> 12) & 15) | 224;
		str[1] = ((wc >> 6) & 63) | 128;
		str[2] = ((wc >> 0) & 63) | 128;
	}
	else if (wc < 1114112)
	{
		str[0] = ((wc >> 18) & 7) | 240;
		str[1] = ((wc >> 12) & 63) | 128;
		str[2] = ((wc >> 6) & 63) | 128;
		str[3] = ((wc >> 0) & 63) | 128;
	}
	return (str);
}

char			*ft_get_wchar_t(wchar_t wc)
{
	char *str;

	if (wc < 128)
		str = ft_strnew(1);
	else if (wc < 2048)
		str = ft_strnew(2);
	else if (wc < 65536)
		str = ft_strnew(3);
	else if (wc < 1114112)
		str = ft_strnew(4);
	if (wc < 1114112 && ((str)))
	{
		str = ft_convert(wc, str);
		return (str);
	}
	return (NULL);
}
