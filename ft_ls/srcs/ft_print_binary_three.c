/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_binary_three.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 18:49:46 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/22 18:34:14 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_pbt(t_file *file, t_ls *ls, int nb_files, int *i)
{
	if (file->prev != NULL)
		ft_pbt(file->prev, ls, nb_files, i);
	if (ft_strchr(ls->options, 'l') != NULL)
		print_file_l(file, ls);
	else
	{
		print_file(file, ls);
		if (nb_files == 0 || ft_strchr(ls->options, '1') != NULL ||
				(((file->parent != NULL
			&& ft_strchr(ls->options, 'x') != NULL && *i % nb_files == 0))
					&& *i < file->parent->nb_sub))
			ft_putchar('\n');
	}
	i[0]++;
	if (file->next != NULL)
		ft_pbt(file->next, ls, nb_files, i);
}
