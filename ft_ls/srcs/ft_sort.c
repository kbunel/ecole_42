/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 12:53:25 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/22 18:34:14 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static t_file		*init_s_files(t_file *files)
{
	int			i;

	i = 0;
	files->prev = NULL;
	while (files->next != NULL && files->name[i] <= files->next->name[i])
	{
		i = 0;
		while (files->name[i] == files->next->name[i])
			i++;
		if (files->name[i] < files->next->name[i])
			files = files->next;
	}
	return (files);
}

static void			insert_files(t_file *s_files, t_file *files)
{
	int			i;

	i = 0;
	while (s_files->next != NULL && files->name[i] >= s_files->next->name[i])
	{
		i = 0;
		while (files->name[i] == s_files->next->name[i])
			i++;
		if (files->name[i] > s_files->next->name[i])
		{
			s_files = s_files->next;
			i = 0;
		}
	}
	files->prev = s_files;
	files->next = s_files->next;
	if (s_files->next != NULL)
		s_files->next->prev = files;
	s_files->next = files;
}

static int			is_before_first(t_file *first, t_file *files)
{
	int		i;

	i = 0;
	while (first->name[i] != '\0' && files->name[i] == first->name[i])
		i++;
	if (files->name[i] < first->name[i])
		return (1);
	else
		return (0);
}

static t_file		*insert_before(t_file *first, t_file *files)
{
	first->prev = files;
	files->prev = NULL;
	files->next = first;
	return (files);
}

t_file				*ft_sort_ascii(t_file *files)
{
	t_file		*s_files;
	t_file		*g_file;
	t_file		*first;

	first = files;
	if (files != NULL && files->next != NULL)
	{
		s_files = init_s_files(files);
		files = s_files->next;
		s_files->next = NULL;
		while (files != NULL)
		{
			g_file = files;
			files = files->next;
			if ((is_before_first(first, g_file)))
				first = insert_before(first, g_file);
			else
				insert_files(first, g_file);
		}
	}
	return (first);
}
