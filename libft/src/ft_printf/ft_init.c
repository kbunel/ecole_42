/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 14:46:26 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/04 21:37:14 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

void	ft_first_arg(t_printf *conv)
{
	t_arg	*arg;

	if ((arg = (t_arg *)malloc(sizeof(t_arg))))
	{
		arg->value = NULL;
		arg->next = NULL;
		conv->arg = arg;
		conv->arg_first = arg;
	}
	else
		ft_error_msg(0, NULL, 0, 0);
}

int		ft_init_start(t_printf *conv)
{
	conv->return_value = 0;
	conv->size_param = 0;
	conv->wc_arg = 0;
	conv->nb_sign = '+';
	conv->flag = NULL;
	conv->mfw = NULL;
	conv->precision = NULL;
	conv->has_precision = 0;
	conv->length = NULL;
	conv->letter = '_';
	conv->garbage = 0;
	conv->error_letter = NULL;
	conv->display_errors = DISP_ERROR;
	conv->count_errors = 0;
	conv->r_v_minus = 0;
	conv->fd = 1;
	ft_first_arg(conv);
	return (0);
}

void	ft_init_during(t_printf *conv)
{
	conv->nb_sign = '+';
	if (conv->flag != NULL)
		ft_memdel((void **)&conv->flag);
	if (conv->mfw != NULL)
		ft_memdel((void **)&conv->mfw);
	if (conv->precision != NULL)
		ft_memdel((void **)&conv->precision);
	if (conv->length != NULL)
		ft_memdel((void **)&conv->length);
	if (conv->error_letter != NULL)
		ft_memdel((void **)&conv->error_letter);
	conv->letter = '\0';
}
