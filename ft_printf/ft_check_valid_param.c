/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid_param.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 17:43:30 by kbunel            #+#    #+#             */
/*   Updated: 2016/03/13 19:24:11 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		ft_check_letter(char *fmt, int i, t_printf *conv)
{
	char	c;

	c = fmt[i];
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || c == 'i'
			|| c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x'
			|| c == 'X' || c == 'c' || c == 'C' || c == '%' || c == 'n'
			|| c == 'b' || c == 'B')
		conv->letter = c;
	else
	{
		if (conv->error_letter != NULL)
			ft_memdel((void **)conv->error_letter);
		if (fmt[i] == '\0')
			conv->error_letter = ft_strdup("eol");
		else
			conv->error_letter = ft_strsub(fmt, i, 1);
	}
}

int				ft_check_param(char *fmt, int i, t_printf *conv)
{
	int		a;

	if (conv->wc_arg == 0)
	{
		a = i;
		i += is_flag(fmt, i, &conv[0]);
		i += is_mfw(fmt, i, &conv[0]);
		i += is_precision(fmt, i, &conv[0]);
		i += is_length(fmt, i, &conv[0]);
		while (fmt[i] == ' ')
			i++;
		i += is_letter(fmt[i], &conv[0]);
		conv->size_param = i - a;
		if (conv->letter == '*')
		{
			conv->prec_err = 0;
			conv->flag_err = 0;
			conv->size_param = ft_get_param(fmt, a, conv) + 1;
			ft_check_letter(fmt, a + conv->size_param - 1, conv);
			if (conv->display_errors == 1 && conv->count_errors++ >= 0)
				ft_error_msg(1, fmt, a, i - a);
		}
	}
	return ((conv->error_letter != NULL
				&& ft_strcmp(conv->error_letter, "eol") == 0) ? 0 : 1);
}
