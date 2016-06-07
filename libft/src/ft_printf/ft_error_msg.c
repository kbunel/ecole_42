/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 13:55:01 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/06 14:56:15 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

static char		*ft_modif_retour(char *str)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	while (str[i] != '\0')
		if (str[i++] == '\n')
			j++;
	new_str = ft_strnew(ft_strlen(str) + j);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			i++;
		else
			new_str[j++] = str[i++];
	}
	return (new_str);
}

static void		ft_display_error_msg(char *disp_err)
{
	ft_putendl("\033[1;31merror:\033[0m Invalid Conversion:");
	ft_putendl("\033[1m      [-Werror,-Wformat-invalid-specifier]\033[0m");
	ft_putstr("                ft_printf(\"");
	ft_putstr(disp_err);
	ft_putendl("\");");
}

static void		ft_conversion_error(char *str, int i, int size_arg)
{
	char	*disp_err;
	char	*disp_err_2;
	int		begin;
	int		end;
	int		a;

	a = 0;
	begin = (i - 50 >= 0) ? 50 : 0;
	end = (ft_strlen(str) - i > 50) ? 50 : ft_strlen(str) - begin;
	disp_err_2 = ft_modif_retour(str);
	disp_err = ft_strsub(disp_err_2, begin, end);
	ft_memdel((void **)&disp_err_2);
	ft_display_error_msg(disp_err);
	ft_memdel((void **)&disp_err);
	while (begin++ < i + 26 + size_arg)
	{
		if (str[begin] == '\t')
			while (a++ <= 5)
				ft_putchar(' ');
		ft_putchar(' ');
	}
	ft_putendl("~^~~~~~~~~~~\n");
}

void			ft_error_msg(int error, char *str, int i, int arg_size)
{
	if (error == 0)
	{
		ft_putstr("Exit: Malloc failed");
		exit(1);
	}
	else if (error == 1)
		ft_conversion_error(str, i, arg_size);
	else if (error == -1)
	{
		ft_printf("%d error", i);
		(i > 1) ? ft_putchar('s') : 0;
		ft_putendl(" generated.");
	}
}
