/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 13:15:47 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/22 18:34:14 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_file			*new_sub_file(struct dirent *dp, t_file *parent, char *path,
		t_ls *ls)
{
	t_file			*new_file;

	new_file = init_file(dp, parent, path, NULL);
	ft_get_stat(new_file, parent, NULL, ls);
	get_lens(new_file);
	new_file->prev = NULL;
	return (new_file);
}

void			new_p_file(t_ls *ls, char *path)
{
	t_file			*new_file;
	t_file			*g_file;

	new_file = init_file(NULL, ls->empty_file, path, path);
	new_file->argu = 1;
	ft_get_stat(new_file, ls->empty_file, path, ls);
	get_lens(new_file);
	if (ls->files == NULL)
	{
		new_file->prev = NULL;
		ls->files = new_file;
		ls->empty_file->sub = new_file;
	}
	else
	{
		g_file = ls->files;
		while (g_file->next != NULL)
			g_file = g_file->next;
		g_file->next = new_file;
		new_file->prev = g_file;
	}
}
