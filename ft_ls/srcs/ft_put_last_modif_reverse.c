/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_last_modif_reverse.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 14:58:16 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/22 18:34:14 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		check_ascii(t_file *file, t_file *g_file, int i)
{
	if (file->name[i] == g_file->name[i])
		check_ascii(file, g_file, ++i);
	else if (file->name[i] > g_file->name[i])
	{
		if (g_file->prev != NULL)
			ft_put_last_modif_reverse(file, file->parent, g_file->prev, -1);
		else
			g_file->prev = file;
	}
	else if (file->name[i] < g_file->name[i])
	{
		if (g_file->next != NULL)
			ft_put_last_modif_reverse(file, file->parent, g_file->next, -1);
		else
			g_file->next = file;
	}
}

static void		check_nano_secondes(t_file *file, t_file *g_file)
{
	if (file->nntimespec == g_file->nntimespec)
		check_ascii(file, g_file, 0);
	else if (file->nntimespec < g_file->nntimespec)
	{
		if (g_file->prev != NULL)
			ft_put_last_modif_reverse(file, file->parent, g_file->prev, -1);
		else
			g_file->prev = file;
	}
	else if (file->nntimespec > g_file->nntimespec)
	{
		if (g_file->next != NULL)
			ft_put_last_modif_reverse(file, file->parent, g_file->next, -1);
		else
			g_file->next = file;
	}
}

void			ft_put_last_modif_reverse(t_file *file, t_file *parent,
		t_file *g_file, int i)
{
	if (i == -1 && file->ntimespec == g_file->ntimespec)
		check_nano_secondes(file, g_file);
	else if (i == -1 && file->ntimespec < g_file->ntimespec)
	{
		if (g_file->prev != NULL)
			ft_put_last_modif_reverse(file, parent, g_file->prev, -1);
		else
			g_file->prev = file;
	}
	else if (i == -1 && file->ntimespec > g_file->ntimespec)
	{
		if (g_file->next != NULL)
			ft_put_last_modif_reverse(file, parent, g_file->next, -1);
		else
			g_file->next = file;
	}
}
