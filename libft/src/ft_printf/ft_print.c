/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 20:10:41 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/06 14:57:52 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

static t_printf		*ft_modif_arg(t_printf *conv)
{
	char	l;

	if (conv->letter == 'D' || conv->letter == 'O' || conv->letter == 'U'
			|| conv->letter == 'C' || conv->letter == 'S'
			|| conv->letter == 'p' || conv->letter == 'B')
	{
		if (conv->letter != 'p')
		{
			l = conv->letter + 32;
			conv->letter = l;
		}
		if (conv->length != NULL)
			ft_memdel((void **)&conv->length);
		conv->length = ft_strdup("l");
	}
	return (conv);
}

static void			ft_select_arg(t_printf *conv, void *ap)
{
	if (conv->letter == 'd' || conv->letter == 'i'
			|| conv->letter == 'u' || conv->letter == 'o'
			|| conv->letter == 'x' || conv->letter == 'X'
			|| conv->letter == '%' || conv->letter == 'p'
			|| conv->letter == '*' || conv->letter == 'b')
		ft_print_dioux(ap, conv);
	else if (conv->letter == 's' || conv->letter == 'c')
		ft_print_s(ap, conv);
	else if (conv->letter == 'f')
		conv->fd = (int)ap;
	else if (conv->letter == 'n')
		ft_print_n(ap, *conv);
}

static int			ft_check_mfw(void *ap, t_printf *conv)
{
	int		a;

	if ((conv->mfw != NULL && ft_strcmp(conv->mfw, "*") == 0))
	{
		a = (int)ap;
		if ((int)ap < 0)
			conv->flag = (conv->flag != NULL) ? ft_strjoin(conv->flag, "-") :
				ft_strdup("-");
		if (conv->mfw != NULL)
			ft_memdel((void **)&conv->mfw);
		conv->mfw = (a >= 0) ? ft_itoa(a) : ft_itoa(a * -1);
		return (1);
	}
	return (0);
}

void				ft_print(void *ap, t_printf *conv)
{
	if (ft_check_mfw(ap, conv) > 0)
		conv->wc_arg = conv->wc_arg;
	else if (conv->precision != NULL && ft_strcmp(conv->precision, "*") == 0)
	{
		ft_memdel((void **)&conv->precision);
		conv->precision = ft_itoa((int)ap);
	}
	else if (conv->garbage == 1)
		conv->garbage = 0;
	else
	{
		conv->wc_arg = 0;
		ft_select_arg(ft_modif_arg(conv), ap);
	}
}
