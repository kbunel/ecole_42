/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_csfs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 16:41:24 by kbunel            #+#    #+#             */
/*   Updated: 2016/03/23 16:09:58 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

int		is_flag(char *fmt, int i, t_printf *conv)
{
	int		a;

	a = i;
	while (fmt[i] == '-' || fmt[i] == '+' || fmt[i] == ' '
			|| fmt[i] == '#' || fmt[i] == '0')
		i++;
	if (i > a)
	{
		conv->flag = ft_strsub(fmt, a, i - a);
		return (i - a);
	}
	else
	{
		conv->flag = NULL;
		return (0);
	}
}

int		is_mfw(char *fmt, int i, t_printf *conv)
{
	int		a;
	int		b;

	if ((ft_isdigit(fmt[i])) && (a = i))
	{
		while ((ft_isdigit(fmt[i])))
			i++;
		conv->mfw = ft_strsub(fmt, a, i - a);
		return (i - a);
	}
	else if (fmt[i] == '*' && (a = i) && ++conv->wc_arg > 0)
	{
		while (fmt[i] == '*')
			i++;
		b = i;
		while (ft_isdigit(fmt[i]))
			i++;
		if (b < i && (conv->garbage = 1))
			conv->mfw = ft_strsub(fmt, b, i - b);
		else
			conv->mfw = ft_strsub(fmt, a, i - a);
		return (i - a);
	}
	conv->mfw = NULL;
	return (0);
}

int		is_precision(char *fmt, int i, t_printf *conv)
{
	int		a;

	if (fmt[i] == '.')
	{
		a = i++;
		conv->has_precision = 1;
		if (fmt[i] == '*')
		{
			conv->precision = ft_strdup("*");
			conv->wc_arg++;
			return (2);
		}
		else
		{
			while ((ft_isdigit(fmt[i])))
				i++;
			if (ft_isdigit(fmt[a + 1]))
				conv->precision = ft_strsub(fmt, a + 1, i - a - 1);
			return (i - a);
		}
	}
	conv->precision = NULL;
	return (0);
}

int		is_length(char *fmt, int i, t_printf *conv)
{
	if (fmt[i] == 'h' && fmt[i + 1] == 'h')
		conv->length = ft_strdup("hh");
	else if (fmt[i] == 'l' && fmt[i + 1] == 'l')
		conv->length = ft_strdup("ll");
	else if (fmt[i] == 'h' || fmt[i] == 'l' || fmt[i] == 'j'
			|| fmt[i] == 'z' || fmt[i] == 't' || fmt[i] == 'L')
		conv->length = ft_strsub(&fmt[i], 0, 1);
	else
	{
		conv->length = NULL;
		return (0);
	}
	return (ft_strlen(conv->length));
}

int		is_letter(char c, t_printf *conv)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || c == 'i'
			|| c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x'
			|| c == 'X' || c == 'c' || c == 'C' || c == '%' || c == 'n'
			|| c == 'b')
	{
		conv->letter = c;
		return (1);
	}
	else
		conv->letter = '*';
	return (0);
}
