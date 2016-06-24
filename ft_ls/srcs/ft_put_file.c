/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 18:53:02 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/22 18:34:14 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		ft_put_ascii_reverse(t_file *file, t_file *parent,
		t_file *g_file, int i)
{
	if (g_file->name[i] == file->name[i])
		ft_put_ascii_reverse(file, parent, g_file, ++i);
	else if (g_file->name[i] < file->name[i])
	{
		if (g_file->prev != NULL)
			ft_put_ascii_reverse(file, parent, g_file->prev, 0);
		else
			g_file->prev = file;
	}
	else if (g_file->name[i] > file->name[i])
	{
		if (g_file->next != NULL)
			ft_put_ascii_reverse(file, parent, g_file->next, 0);
		else
			g_file->next = file;
	}
}

static void		ft_put_ascii(t_file *file, t_file *parent,
		t_file *g_file, int i)
{
	if (g_file->name[i] == file->name[i])
		ft_put_ascii(file, parent, g_file, ++i);
	else if (g_file->name[i] > file->name[i])
	{
		if (g_file->prev != NULL)
			ft_put_ascii(file, parent, g_file->prev, 0);
		else
			g_file->prev = file;
	}
	else if (g_file->name[i] < file->name[i])
	{
		if (g_file->next != NULL)
			ft_put_ascii(file, parent, g_file->next, 0);
		else
			g_file->next = file;
	}
}

static void		ft_put_none(t_file *file, t_file *parent, t_file *g_file)
{
	if (g_file->next != NULL)
		ft_put_none(file, parent, g_file->next);
	else
		g_file->next = file;
}

void			ft_put_file(t_file *file, t_file *parent, t_ls *ls)
{
	if (parent->sub == NULL)
		parent->sub = file;
	else if (ft_strchr(ls->options, 'f') == NULL)
	{
		if (ft_strchr(ls->options, 't') != NULL)
		{
			if (ft_strchr(ls->options, 'u') != NULL
					&& ft_strchr(ls->options, 'r') != NULL)
				ft_put_last_access_reverse(file, parent, parent->sub, -1);
			else if (ft_strchr(ls->options, 'u') != NULL)
				ft_put_last_access(file, parent, parent->sub, -1);
			else if (ft_strchr(ls->options, 'r') != NULL)
				ft_put_last_modif_reverse(file, parent, parent->sub, -1);
			else
				ft_put_last_modif(file, parent, parent->sub, -1);
		}
		else if (ft_strchr(ls->options, 'r') != NULL)
			ft_put_ascii_reverse(file, parent, parent->sub, 0);
		else
			ft_put_ascii(file, parent, parent->sub, 0);
	}
	else
		ft_put_none(file, parent, parent->sub);
}
