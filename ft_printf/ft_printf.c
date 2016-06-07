/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 17:45:16 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/07 16:47:14 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		ft_add_color(char *fmt, int i, t_printf *conv)
{
	int		a;

	a = i;
	while (fmt[a] != '}' && fmt[a] != '%' && fmt[a] != '\0')
		a++;
	if (fmt[a] == '}')
		return (ft_color(fmt, i, a - i + 1, conv));
	else
	{
		conv->arg = ft_new_arg(conv->arg);
		conv->arg->value = ft_strsub(fmt, i, a - i);
		conv->arg->size = a - i;
		conv->return_value += a - i;
		return (a);
	}
}

static int		ft_printf_not_argue(t_printf *conv, char *fmt, int i)
{
	int		a;

	a = i;
	while (fmt[a] != '%' && fmt[a] != '\0' && fmt[a] != '{')
		a++;
	conv->arg = ft_new_arg(conv->arg);
	conv->arg->value = ft_strsub(fmt, i, a - i);
	conv->arg->size = a - i;
	conv->return_value += a - i;
	if (fmt[a] == '{')
		a = ft_add_color(fmt, a, conv);
	return (a);
}

static int		ft_print_all(t_printf *conv)
{
	int		i;
	char	*print;
	t_arg	*arg;

	i = 0;
	arg = NULL;
	print = ft_strnew(conv->return_value);
	while (conv->arg_first->next != NULL)
	{
		print = ft_strisub(print, conv->arg_first->value, i);
		i += conv->arg_first->size;
		free(conv->arg_first->value);
		arg = conv->arg_first;
		conv->arg_first = conv->arg_first->next;
		free(arg);
	}
	if (conv->arg_first->value != NULL)
		print = ft_strisub(print, conv->arg_first->value, i);
	free(conv->arg_first->value);
	free(conv->arg_first);
	(conv->count_errors > 0)
		? ft_error_msg(-1, NULL, conv->count_errors, 0) : 0;
	write(1, print, conv->return_value);
	free(print);
	return (conv->return_value - conv->r_v_minus);
}

int				ft_printf(char *fmt, ...)
{
	t_printf	conv;
	va_list		ap;
	int			i;

	i = ft_init_start(&conv);
	va_start(ap, fmt);
	while (fmt[i] != '\0')
	{
		i = ft_printf_not_argue(&conv, fmt, i);
		while (fmt[i] == '%' && fmt[++i] != '\0')
		{
			if (ft_check_param(fmt, i, &conv) == 1)
			{
				(fmt[i] == '%' || conv.letter == '*') ? ft_print(NULL, &conv)
					: ft_print(va_arg(ap, char *), &conv);
				i += (conv.wc_arg != 0) ? -1 : conv.size_param;
				(conv.wc_arg != 0) ? 1 : ft_init_during(&conv);
			}
			else
				i += conv.size_param - 1;
		}
	}
	va_end(ap);
	return (ft_print_all(&conv));
}
