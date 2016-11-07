/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_error_param.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 01:13:09 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/13 15:30:54 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

static int		ft_get_mfw_err(char *fmt, int i, t_printf *conv)
{
	int		a;

	a = i;
	if (fmt[a++] == '*')
		conv->wc_arg++;
	else
		while (fmt[a] >= 48 && fmt[a] < 58)
			a++;
	if (conv->mfw != NULL)
		ft_memdel((void **)&conv->mfw);
	conv->mfw = ft_strsub(fmt, i, a - i);
	return (a - i);
}

static int		ft_get_precision_err(char *fmt, int i, t_printf *conv)
{
	int		a;

	a = i;
	if (fmt[a++] == '*')
		conv->wc_arg++;
	else
		while (fmt[a] >= 48 && fmt[a] < 58)
			a++;
	if (conv->precision != NULL)
		ft_memdel((void **)&conv->precision);
	conv->precision = ft_strsub(fmt, i, a - i);
	return (a - i);
}

static int		ft_get_flag_err(char *fmt, int i, t_printf *conv)
{
	int		a;

	a = i;
	while (fmt[i] == '-' || fmt[i] == '+' || fmt[i] == ' ' || fmt[i] == '#')
		i++;
	if (conv->flag != NULL && conv->flag_err == 0)
	{
		ft_memdel((void **)&conv->flag);
		conv->flag = ft_strsub(fmt, a, i - a);
		conv->flag_err++;
		return (i - a);
	}
	else if (conv->flag == NULL)
	{
		conv->flag = ft_strsub(fmt, a, i - a);
		conv->flag_err++;
		return (i - a);
	}
	conv->flag = ft_strjoin_free(conv->flag, ft_strsub(fmt, a, i - a));
	return (i - a);
}

static int		ft_get_length_err(char *fmt, int i, t_printf *conv)
{
	int		a;

	a = i;
	if (conv->length != NULL && ft_strcmp(conv->length, "ll") != 0)
	{
		ft_memdel((void **)&conv->length);
		conv->length = ft_strdup("ll");
	}
	else if (!(conv->length != NULL && ft_strcmp(conv->length, "ll") == 0))
		conv->length = ft_strdup("ll");
	while (fmt[i] == 'h' || fmt[i] == 'l' || fmt[i] == 'j' || fmt[i] == 'z'
			|| fmt[i] == 't' || fmt[i] == 'L')
		i++;
	return (i - a);
}

int				ft_get_param(char *fmt, int i, t_printf *conv)
{
	char	c;
	int		a;

	a = i;
	while (fmt[a] != '\0' && (c = fmt[a]))
	{
		if (c == '.' && conv->prec_err++)
			a++;
		else if (c == '-' || c == '+' || c == ' ' || c == '#' || c == '\'')
			a += ft_get_flag_err(fmt, a, conv);
		else if (c == 'h' || c == 'l' || c == 'j' || c == 'z' || c == 't'
				|| c == 'L')
			a += ft_get_length_err(fmt, a, conv);
		else if (c == '.' || c == '0')
			a++;
		else if (((c > 48 && c < 58) || c == '*') && conv->prec_err == 0)
			a += ft_get_mfw_err(fmt, a, conv);
		else if (((c > 48 && c < 58) || c == '*') && conv->prec_err == 1)
			a += ft_get_precision_err(fmt, a, conv);
		else if (((c > 48 && c < 58) || c == '*'))
			a++;
		else
			break ;
	}
	return (a - i);
}
