/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 18:56:12 by kbunel            #+#    #+#             */
/*   Updated: 2016/03/29 18:59:54 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

static void		ft_get_color(int i, t_printf *conv)
{
	conv->arg = ft_new_arg(conv->arg);
	if (i == 0)
		conv->arg->value = ft_strdup("\033[0m");
	else if (i == 1)
		conv->arg->value = ft_strdup("\033[30m");
	else if (i == 2)
		conv->arg->value = ft_strdup("\033[31m");
	else if (i == 3)
		conv->arg->value = ft_strdup("\033[32m");
	else if (i == 4)
		conv->arg->value = ft_strdup("\033[33m");
	else if (i == 5)
		conv->arg->value = ft_strdup("\033[34m");
	else if (i == 6)
		conv->arg->value = ft_strdup("\033[35m");
	else if (i == 7)
		conv->arg->value = ft_strdup("\033[36m");
	else if (i == 8)
		conv->arg->value = ft_strdup("\033[37m");
	conv->arg->size = (i == 0) ? 6 : 7;
	conv->r_v_minus = (i == 0) ? 6 : 7;
	conv->return_value += (i == 0) ? 6 : 7;
}

static void		ft_not_color(char *no_color, t_printf *conv)
{
	conv->arg = ft_new_arg(conv->arg);
	conv->arg->value = ft_strdup(no_color);
	conv->arg->size = ft_strlen(no_color);
	conv->return_value += ft_strlen(no_color);
}

int				ft_color(char *fmt, int i, int size, t_printf *conv)
{
	char	*color;

	color = ft_strsub(fmt, i, size);
	if (ft_strcmp(color, "{eoc}") == 0)
		ft_get_color(0, conv);
	else if (ft_strcmp(color, "{black}") == 0)
		ft_get_color(1, conv);
	else if (ft_strcmp(color, "{red}") == 0)
		ft_get_color(2, conv);
	else if (ft_strcmp(color, "{green}") == 0)
		ft_get_color(3, conv);
	else if (ft_strcmp(color, "{yellow}") == 0)
		ft_get_color(4, conv);
	else if (ft_strcmp(color, "{blue}") == 0)
		ft_get_color(5, conv);
	else if (ft_strcmp(color, "{pink}") == 0)
		ft_get_color(6, conv);
	else if (ft_strcmp(color, "{cyan}") == 0)
		ft_get_color(7, conv);
	else if (ft_strcmp(color, "{grey}") == 0)
		ft_get_color(8, conv);
	else
		ft_not_color(color, conv);
	ft_memdel((void **)&color);
	return (i + size);
}
