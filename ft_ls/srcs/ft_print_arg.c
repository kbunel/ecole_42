/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 11:52:53 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/22 18:34:14 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			ft_print_arg(t_file *file, t_ls *ls)
{
	if (ft_strchr(ls->options, 'l') != NULL)
		print_file_l(file, ls);
	else
	{
		print_file(file, ls);
		if (ft_strchr(ls->options, '1') != NULL)
			ft_putchar('\n');
	}
}
