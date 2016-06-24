/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 12:14:21 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/22 18:34:14 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static t_file		*assign(t_ls *ls, t_file *parent, t_file *first)
{
	if (parent != NULL)
		parent->sub = first;
	else
		ls->files = first;
	return (first);
}

void				ft_get_sort(t_ls *ls, t_file *parent, t_file *file)
{
	while (file != NULL && file->prev != NULL)
		file = file->prev;
	if (ft_strchr(ls->options, 'f') == NULL)
	{
		if (ft_strchr(ls->options, 't') != NULL)
		{
			if (ft_strchr(ls->options, 'u') != NULL)
				file = assign(ls, parent, ft_sort_time_last_access(file));
			else
				file = assign(ls, parent, ft_sort_time(file));
		}
		else
			file = assign(ls, parent, ft_sort_ascii(file));
		if (ft_strchr(ls->options, 'r') != NULL)
			assign(ls, parent, ft_sort_reverse(file));
	}
}
