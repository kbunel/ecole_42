/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:43:03 by kbunel            #+#    #+#             */
/*   Updated: 2016/03/23 16:09:58 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

static char		*ft_get_length_x(t_printf *conv, void *ap)
{
	if (conv->length != NULL)
	{
		if (ft_strcmp(conv->length, "hh") == 0)
			return (ft_itoa_printf_hexa((unsigned char)ap, conv));
		else if (ft_strcmp(conv->length, "h") == 0)
			return (ft_itoa_printf_hexa((unsigned short)ap, conv));
		else if (ft_strcmp(conv->length, "l") == 0)
			return (ft_itoa_printf_hexa((unsigned long)ap, conv));
		else if (ft_strcmp(conv->length, "ll") == 0)
			return (ft_itoa_printf_hexa((unsigned long long)ap, conv));
		else if (ft_strcmp(conv->length, "j") == 0)
			return (ft_itoa_printf_hexa_j((uintmax_t)ap, conv));
		else if (ft_strcmp(conv->length, "z") == 0)
			return (ft_itoa_printf_hexa((size_t)ap, conv));
	}
	else
		return (ft_itoa_printf_hexa((unsigned)ap, conv));
	return (NULL);
}

static char		*ft_get_length_o(t_printf *conv, void *ap)
{
	if (conv->length != NULL)
	{
		if (ft_strcmp(conv->length, "hh") == 0)
			return (ft_itoa_printf_octal((unsigned char)ap, conv));
		else if (ft_strcmp(conv->length, "h") == 0)
			return (ft_itoa_printf_octal((unsigned short)ap, conv));
		else if (ft_strcmp(conv->length, "l") == 0)
			return (ft_itoa_printf_octal((unsigned long)ap, conv));
		else if (ft_strcmp(conv->length, "ll") == 0)
			return (ft_itoa_printf_octal((unsigned long long)ap, conv));
		else if (ft_strcmp(conv->length, "j") == 0)
			return (ft_itoa_printf_octal_j((uintmax_t)ap));
		else if (ft_strcmp(conv->length, "z") == 0)
			return (ft_itoa_printf_octal((size_t)ap, conv));
	}
	else
		return (ft_itoa_printf_octal((unsigned)ap, conv));
	return (NULL);
}

static char		*ft_get_length_u(t_printf *conv, void *ap)
{
	if (conv->length != NULL)
	{
		if (ft_strcmp(conv->length, "hh") == 0)
			return (ft_itoa_printf_ull((unsigned char)ap));
		else if (ft_strcmp(conv->length, "h") == 0)
			return (ft_itoa_printf_ull((unsigned short)ap));
		else if (ft_strcmp(conv->length, "l") == 0)
			return (ft_itoa_printf_ull((unsigned long)ap));
		else if (ft_strcmp(conv->length, "ll") == 0)
			return (ft_itoa_printf_ull((unsigned long long)ap));
		else if (ft_strcmp(conv->length, "j") == 0)
			return (ft_itoa_printf_ull((uintmax_t)ap));
		else if (ft_strcmp(conv->length, "z") == 0)
			return (ft_itoa_printf_ull((size_t)ap));
	}
	else
		return (ft_itoa_printf((unsigned)ap, conv));
	return (NULL);
}

static char		*ft_get_length_d_i(t_printf *conv, void *ap)
{
	if (conv->length != NULL)
	{
		if (ft_strcmp(conv->length, "hh") == 0)
			return (ft_itoa_printf((signed char)ap, conv));
		else if (ft_strcmp(conv->length, "h") == 0)
			return (ft_itoa_printf((short)ap, conv));
		else if (ft_strcmp(conv->length, "l") == 0)
			return (ft_itoa_printf((long)ap, conv));
		else if (ft_strcmp(conv->length, "ll") == 0)
			return (ft_itoa_printf((unsigned long long int)ap, conv));
		else if (ft_strcmp(conv->length, "j") == 0)
			return (ft_itoa_printf((intmax_t)ap, conv));
		else if (ft_strcmp(conv->length, "z") == 0)
			return (ft_itoa_printf((size_t)ap, conv));
	}
	else
		return (ft_itoa_printf((signed)ap, conv));
	return (NULL);
}

char			*ft_get_length(t_printf *conv, void *ap)
{
	if (conv->letter == '%')
		return (ft_strdup("%"));
	else if (conv->letter == '*')
		return (ft_strdup(conv->error_letter));
	else if (ap == NULL && conv->has_precision != 1
			&& (!(conv->letter == 'o' && ft_strchr(conv->flag, '#') != NULL)))
		return (ft_strdup("0"));
	else if (ap == NULL)
		return (NULL);
	else if (conv->letter == 'd' || conv->letter == 'i')
		return (ft_get_length_d_i(conv, ap));
	else if (conv->letter == 'u')
		return (ft_get_length_u(conv, ap));
	else if (conv->letter == 'o')
		return (ft_get_length_o(conv, ap));
	else if (conv->letter == 'x' || conv->letter == 'X' || conv->letter == 'p')
		return (ft_get_length_x(conv, ap));
	else if (conv->letter == 'b')
		return (ft_get_length_b(conv, ap));
	return (NULL);
}
