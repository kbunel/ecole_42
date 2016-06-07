/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 18:56:17 by kbunel            #+#    #+#             */
/*   Updated: 2016/03/12 17:57:59 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*ft_get_length_s(t_printf *conv, void *ap)
{
	char	*print;

	if (conv->letter == 'c'
			&& (!(conv->length != NULL && ft_strcmp(conv->length, "l") == 0)))
	{
		print = ft_strnew(1);
		print[0] = (int)ap;
		return (print);
	}
	else if (ap == NULL && conv->letter != 'c')
		return (ft_strdup("(null)"));
	else if (conv->letter == 'c')
		return (ft_get_wchar_t((wchar_t)ap));
	else if (conv->length != NULL && ft_strcmp(conv->length, "l") == 0)
		return (ft_get_w_string((wchar_t *)ap, *conv));
	else if (conv->precision != NULL
			&& ft_atoi(conv->precision) < (int)ft_strlen((char *)ap))
		return (ft_strsub((char *)ap, 0, ft_atoi(conv->precision)));
	else if (conv->has_precision == 1 && conv->precision == NULL)
		return (NULL);
	else
		return (ft_strdup((char *)ap));
}

static int		ft_print_space(int i, t_printf conv, int ap_length, int b)
{
	int		mfw;

	if (ft_strichr(conv.flag, 0, '-') == -1
			&& ft_strichr(conv.flag, 0, '0') >= 0 && conv.mfw != NULL
			&& ap_length < ft_atoi(conv.mfw))
		ap_length = ft_atoi(conv.mfw);
	if (((ft_strichr(conv.flag, 0, '-') == -1 && b == 0)
				|| (ft_strichr(conv.flag, 0, '-') >= 0 && b == 1))
			&& (conv.mfw != NULL))
	{
		mfw = ft_atoi(conv.mfw);
		while (mfw-- > ap_length)
			conv.arg->value[i++] = ' ';
	}
	return (i);
}

static int		ft_print_zero(int i, t_printf conv, int ap_length)
{
	int		pr;

	if (ft_strchr(conv.flag, '0') != NULL
	&& ft_strchr(conv.flag, '-') == NULL)
	{
		pr = (conv.mfw != NULL) ? ft_atoi(conv.mfw) : 0;
		pr = (conv.precision != NULL) ? ft_atoi(conv.precision) : pr;
		if ((ft_strichr(conv.flag, 0, '+') >= 0
		|| ft_strichr(conv.flag, 0, ' ') >= 0 || conv.nb_sign == '-')
		&& conv.precision == NULL && conv.letter != '*')
			ap_length++;
		while (pr-- > ap_length)
			conv.arg->value[i++] = '0';
	}
	return (i);
}

void			ft_print_s(void *ap, t_printf *conv)
{
	char		*print;
	int			i;
	int			z;
	int			p_len;

	i = 0;
	conv->arg = ft_new_arg(conv->arg);
	print = ft_get_length_s(conv, ap);
	p_len = (print != NULL) ? ft_strlen(print) : 0;
	z = ((int)ap == 0 || ap == NULL) ? 1 : 0;
	conv->return_value += (z == 1 && conv->letter == 'c') ? 1 : 0;
	conv->arg->value = ft_strnew(ft_init_d_i_len(*conv, print) + 1);
	i = ft_print_space(i, *conv, p_len + z, 0);
	i = ft_print_zero(i, *conv, (conv->letter == 'c') ? 1 : p_len);
	(print != NULL) ? ft_strcat(conv->arg->value, print) : 0;
	i += p_len;
	i = ft_print_space(i, *conv, p_len, 1);
	conv->arg->size = i;
	conv->return_value += i;
	(print != NULL) ? free(print) : 0;
}
