/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 17:26:30 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/22 18:34:14 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static t_file		*get_first_file(t_file *r_file)
{
	while (r_file->prev != NULL)
		r_file = r_file->prev;
	return (r_file);
}

t_file				*ft_sort_reverse(t_file *file)
{
	t_file		*r_file;
	t_file		*g_file;

	if (file != NULL)
	{
		while (file->next != NULL)
			file = file->next;
		r_file = file;
		file = file->prev;
		r_file->prev = NULL;
		r_file->next = NULL;
		while (file != NULL)
		{
			g_file = file->prev;
			r_file->next = file;
			r_file->next->prev = r_file;
			r_file->next->next = NULL;
			r_file = r_file->next;
			file = g_file;
			g_file = r_file;
		}
		return (get_first_file(r_file));
	}
	return (NULL);
}
