/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 18:56:31 by kbunel            #+#    #+#             */
/*   Updated: 2016/03/23 16:09:58 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

static int		ft_print_zero(int i, t_printf conv, int ap_length)
{
	int		pr;

	if ((ft_strichr(conv.flag, 0, '0') >= 0
				&& ft_strichr(conv.flag, 0, '-') < 0)
			|| (conv.precision != NULL && conv.letter != '*'))
	{
		pr = (conv.mfw != NULL) ? ft_atoi(conv.mfw) : 0;
		pr = (conv.precision != NULL && conv.letter != '%'
				&& conv.letter != '*')
			? ft_atoi(conv.precision) : pr;
		pr = (conv.letter == 'd' && conv.precision != NULL && conv.mfw != NULL
				&& ft_atoi(conv.precision) < 0) ? ft_atoi(conv.mfw) : pr;
		if ((ft_strchr(conv.flag, '+') != NULL
					|| ft_strchr(conv.flag, ' ') != NULL || conv.nb_sign == '-')
				&& conv.precision == NULL && conv.letter != '*')
			ap_length++;
		else if (ft_strichr(conv.flag, 0, '#') >= 0
				&& (conv.letter == 'o' || conv.letter == 'O'))
			ap_length++;
		else if (conv.letter == 'x' && ft_strichr(conv.flag, 0, '#') >= 0)
			ap_length += 2;
		while (pr-- > ap_length)
			conv.arg->value[i++] = '0';
	}
	return (i);
}

static int		ft_check_ap_length(t_printf conv, int ap_length)
{
	if (conv.precision != NULL && ap_length < ft_atoi(conv.precision)
			&& conv.letter != '%' && conv.letter != '*')
		ap_length = ft_atoi(conv.precision);
	else if (ft_strichr(conv.flag, 0, '-') == -1
			&& ft_strichr(conv.flag, 0, '0') >= 0 && conv.mfw != NULL
			&& ap_length < ft_atoi(conv.mfw))
		ap_length = ft_atoi(conv.mfw);
	if ((ft_strichr(conv.flag, 0, ' ') >= 0
				|| ft_strichr(conv.flag, 0, '+') >= 0
				|| conv.nb_sign == '-') && (conv.letter != 'u'
					&& conv.letter != 'x' && conv.letter != 'X'
					&& conv.letter != '*'))
		ap_length++;
	else if (((conv.letter == 'x' || conv.letter == 'X')
				&& ft_strichr(conv.flag, 0, '#') >= 0) || conv.letter == 'p')
		ap_length += 2;
	else if (conv.letter == 'o' && ft_strichr(conv.flag, 0, '#') >= 0)
		ap_length++;
	return (ap_length);
}

static int		ft_print_space(int i, t_printf conv, int ap_length, int b)
{
	int		mfw;

	if ((ft_strichr(conv.flag, 0, '-') == -1 && b == 0)
			|| (ft_strichr(conv.flag, 0, '-') >= 0 && b == 1))
	{
		if (conv.mfw != NULL)
		{
			mfw = ft_atoi(conv.mfw);
			ap_length = ft_check_ap_length(conv, ap_length);
			while (mfw-- > ap_length)
				conv.arg->value[i++] = ' ';
		}
	}
	return (i);
}

static int		ft_print_flag(int i, t_printf conv, void *ap)
{
	if (((conv.nb_sign)) && conv.nb_sign == '-')
		conv.arg->value[i++] = '-';
	else if (ft_strichr(conv.flag, 0, '+') >= 0 && (conv.letter == 'd'
				|| conv.letter == 'i'))
		conv.arg->value[i++] = '+';
	else if (ft_strichr(conv.flag, 0, ' ') >= 0 && (conv.letter == 'd'
				|| conv.letter == 'i'))
		conv.arg->value[i++] = ' ';
	if (ft_strichr(conv.flag, 0, '#') >= 0 && conv.letter == 'o')
		conv.arg->value[i++] = '0';
	else if ((ft_strchr(conv.flag, '#') != NULL && (!((conv.letter == 'x'
							|| conv.letter == 'X') && (int)ap == 0))
				&& (conv.letter == 'x' || conv.letter == 'X'))
			|| conv.letter == 'p')
	{
		conv.arg->value[i++] = '0';
		conv.arg->value[i++] = (conv.letter == 'x' || conv.letter == 'p')
			? 'x' : 'X';
	}
	return (i);
}

void			ft_print_dioux(void *ap, t_printf *conv)
{
	char		*print;
	int			i;
	int			p_len;

	i = 0;
	conv->arg = ft_new_arg(conv->arg);
	print = ft_get_length(conv, ap);
	p_len = (print != NULL) ? ft_strlen(print) : 0;
	conv->arg->value = ft_strnew(ft_init_d_i_len(*conv, print) + 1);
	i = ft_print_space(i, *conv, p_len, 0);
	i = (conv->letter == '%') ? i : ft_print_flag(i, *conv, ap);
	i = ft_print_zero(i, *conv, p_len);
	(print != NULL) ? ft_strcat(conv->arg->value, print) : 0;
	i += p_len;
	i = ft_print_space(i, *conv, p_len, 1);
	conv->arg->size = i;
	conv->return_value += i;
	(print != NULL) ? free(print) : 0;
}
