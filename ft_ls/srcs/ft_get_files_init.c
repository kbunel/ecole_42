/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_files_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 17:31:56 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/23 14:30:00 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static char			*check_path(t_file *file)
{
	char	*tmp;

	if (file->path != NULL
			&& file->path[ft_strlen(file->path)] != '/')
		tmp = ft_strjoin(file->path, "/");
	else
		tmp = ft_strdup(file->path);
	return (tmp);
}

static void			ft_isreg(t_file *file, t_ls *ls)
{
	int				i;
	struct stat		f_stat;
	char			*l_path;

	i = 0;
	while (file != NULL)
	{
		if (!S_ISDIR(file->type))
		{
			l_path = check_path(file);
			if (!(ft_strchr(ls->options, 'l') == NULL
					&& (S_ISLNK(file->type)
						&& lstat(l_path, &f_stat) != -1
						&& S_ISDIR(f_stat.st_mode))))
			{
				ft_print_arg(file, ls);
				ls->w_reg = 1;
			}
			ft_memdel((void **)&l_path);
			i++;
		}
		file = file->next;
	}
	if (ft_strchr(ls->options, 'x') != NULL && i > 0)
		ft_putchar('\n');
}

static void			ft_isdir_islink(t_file *file, t_ls *ls)
{
	char		*path;
	char		*tmp;
	struct stat	f_stat;

	while (file != NULL)
	{
		if (S_ISDIR(file->type))
			get_files_r(file, file->path, ls);
		else if (ft_strchr(ls->options, 'l') == NULL && S_ISLNK(file->type)
				&& ft_strchr(file->path, '/') != NULL)
		{
			tmp = ft_strsub(file->path, 0,
					ft_strrchr(file->path, '/') - file->path + 1);
			path = ft_strjoin(tmp, file->l_path);
			get_files_r(file, path, ls);
			ft_memdel((void **)&tmp);
			ft_memdel((void **)&path);
		}
		else if (ft_strchr(ls->options, 'l') == NULL && S_ISLNK(file->type)
				&& lstat(file->l_path, &f_stat) != -1
				&& S_ISDIR(f_stat.st_mode))
			get_files_r(file, file->l_path, ls);
		file = file->next;
	}
}

void				ft_get_files_r(t_ls *ls)
{
	t_args			*g_args;
	struct stat		f_stat;

	g_args = ls->args;
	ls->empty_file = new_empty_file();
	while (g_args != NULL)
	{
		if (lstat(g_args->name, &f_stat) != -1)
			new_p_file(ls, g_args->name);
		else
			ft_error_ls(strerror(errno), g_args->name);
		g_args = g_args->next;
	}
	ft_get_sort(ls, NULL, ls->files);
	ft_isreg(ls->files, ls);
	ft_isdir_islink(ls->files, ls);
	ft_free_from_args(ls->files, ls);
}
