/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_time_last_acces.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 18:46:42 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/22 18:34:14 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static t_file		*init_s_files(t_file *files)
{
	int			i;

	files->prev = NULL;
	while (files->next != NULL && files->natimespec >= files->next->natimespec)
		if (files->natimespec == files->next->natimespec)
		{
			i = 0;
			if (files->nnatimespec > files->next->nnatimespec)
				files = files->next;
			else if (files->nnatimespec == files->next->nnatimespec)
			{
				while (files->name[i] == files->next->name[i])
					i++;
				if (files->name[i] < files->next->name[i])
					files = files->next;
				else
					break ;
			}
			else
				break ;
		}
		else
			files = files->next;
	return (files);
}

static void			insert_files(t_file *s_files, t_file *files, int i)
{
	while ((s_files->next) && files->natimespec <= s_files->next->natimespec)
		if (files->natimespec == s_files->next->natimespec)
		{
			i = 0;
			if (files->nnatimespec < s_files->next->nnatimespec)
				s_files = s_files->next;
			else if (files->nnatimespec == s_files->next->nnatimespec)
			{
				while (files->name[i] == s_files->next->name[i])
					i++;
				if (files->name[i] > s_files->next->name[i])
					s_files = s_files->next;
				else
					break ;
			}
			else
				break ;
		}
		else
			s_files = s_files->next;
	files->prev = s_files;
	files->next = s_files->next;
	if (s_files->next != NULL)
		s_files->next->prev = files;
	s_files->next = files;
}

static int			is_before_first(t_file *first, t_file *files, int i)
{
	if (files->natimespec >= first->natimespec)
	{
		if (files->natimespec == first->natimespec)
		{
			if (files->nnatimespec > first->nnatimespec)
				return (1);
			else if (files->nnatimespec > first->nnatimespec)
			{
				while (first->name[i] != '\0'
						&& files->name[i] == first->name[i])
					i++;
				if (files->name[i] < first->name[i])
					return (1);
				else
					return (0);
			}
			else
				return (0);
		}
		else
			return (1);
	}
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

t_file				*ft_sort_time_last_access(t_file *files)
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
			if ((is_before_first(first, g_file, 0)))
				first = insert_before(first, g_file);
			else
				insert_files(first, g_file, 0);
		}
	}
	return (first);
}
