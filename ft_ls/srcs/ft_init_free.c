/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 13:04:00 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/24 17:43:19 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_ls		*ft_init(void)
{
	t_ls	*ls;

	ls = (t_ls *)malloc(sizeof(t_ls));
	ls->files = NULL;
	ls->empty_file = NULL;
	ls->args = NULL;
	ls->options = NULL;
	ls->nb_args = 0;
	ls->opt = 0;
	ls->w_reg = 0;
	errno = 0;
	return (ls);
}

void		ft_free(t_ls *ls)
{
	t_args		*g_args;

	while (ls->args != NULL)
	{
		g_args = ls->args;
		ft_memdel((void **)&g_args->name);
		ls->args = ls->args->next;
		ft_memdel((void **)&g_args);
	}
	if (ls->empty_file != NULL)
		ft_memdel((void **)&ls->empty_file);
	if (ls->options != NULL)
		ft_memdel((void **)&ls->options);
	ft_memdel((void **)&ls);
}

void		free_files(t_file *files)
{
	if (files != NULL)
	{
		if (files->prev != NULL)
			free_files(files->prev);
		if (files->next != NULL)
			free_files(files->next);
		ft_memdel((void **)&files->name);
		ft_memdel((void **)&files->path);
		if (files->stat == 1)
		{
			ft_memdel((void **)&files->pw_name);
			ft_memdel((void **)&files->gr_name);
			ft_memdel((void **)&files->l_path);
		}
		if (files->stat_time == 1)
		{
			ft_memdel((void **)&files->mtimespec);
			ft_memdel((void **)&files->atimespec);
			ft_memdel((void **)&files->hour_year);
			ft_memdel((void **)&files->a_hour_year);
		}
		ft_memdel((void **)&files);
	}
}

void		ft_free_from_args(t_file *files, t_ls *ls)
{
	while (files != NULL)
	{
		ft_memdel((void **)&files->name);
		ft_memdel((void **)&files->path);
		if (files->stat == 1)
		{
			ft_memdel((void **)&files->pw_name);
			ft_memdel((void **)&files->gr_name);
			ft_memdel((void **)&files->mtimespec);
			ft_memdel((void **)&files->atimespec);
			ft_memdel((void **)&files->hour_year);
			ft_memdel((void **)&files->a_hour_year);
			ft_memdel((void **)&files->l_path);
		}
		ls->files = files->next;
		ft_memdel((void **)&files);
		files = ls->files;
	}
}
