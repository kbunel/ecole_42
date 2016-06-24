/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_files_r.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 13:04:28 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/22 18:34:14 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static size_t		get_size(t_file *file, t_ls *ls)
{
	struct winsize		w;
	int					max_elems;
	int					nb_ligne;
	int					nb_elems;

	if (file != NULL && file->nb_sub > 0 && ft_strchr(ls->options, 'x') != NULL
			&& ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) != -1)
	{
		max_elems = w.ws_col / (file->sub_len + 2);
		if (max_elems > 0)
		{
			nb_ligne = file->nb_sub / max_elems;
			if (file->nb_sub % max_elems > 0)
				nb_ligne++;
		}
		else
			nb_ligne = 1;
		nb_elems = file->nb_sub / nb_ligne;
		if (file->nb_sub % nb_ligne > 0)
			nb_elems++;
		return (nb_elems);
	}
	else
		return (0);
}

static void			check_path(t_file *g_file)
{
	char			*sub_path_s;

	if (S_ISDIR(g_file->type) && ft_strcmp(g_file->name, ".") != 0
			&& ft_strcmp(g_file->name, "..") != 0)
	{
		sub_path_s = ft_strdup(g_file->path);
		ft_memdel((void **)&g_file->path);
		g_file->path = ft_strjoin(sub_path_s, "/");
		ft_memdel((void **)&sub_path_s);
	}
}

static void			init(DIR *dir, t_file *parent, char *path, t_ls *ls)
{
	t_file				*g_file;
	struct dirent		*dp;

	while ((dp = readdir(dir)))
	{
		if ((ft_strchr(ls->options, 'a') != NULL
					|| (ft_strchr(ls->options, 'A') != NULL
						&& ft_strcmp(dp->d_name, ".") != 0
						&& ft_strcmp(dp->d_name, "..") != 0)
					|| dp->d_name[0] != '.')
				|| ft_strchr(ls->options, 'f') != NULL)
		{
			g_file = new_sub_file(dp, parent, path, ls);
			check_path(g_file);
			ft_put_file(g_file, parent, ls);
		}
	}
}

static void			get_dir(t_file *file, t_ls *ls)
{
	if (file->prev != NULL)
		get_dir(file->prev, ls);
	if (S_ISDIR(file->type) && ft_strcmp(file->name, ".") != 0
			&& ft_strcmp(file->name, "..") != 0)
		get_files_r(file, file->path, ls);
	if (file->next != NULL)
		get_dir(file->next, ls);
}

void				get_files_r(t_file *parent, char *path, t_ls *ls)
{
	DIR					*dir;
	int					i;

	i = 1;
	print_parent_path(path, ls, parent);
	if ((dir = opendir(path)))
	{
		init(dir, parent, path, ls);
		closedir(dir);
		if (parent->sub != NULL)
		{
			if (ft_strchr(ls->options, 'l') != NULL
					|| ft_strchr(ls->options, 'g') != NULL)
				ft_printf("total %d\n", parent->blocks);
			ft_pbt(parent->sub, ls, get_size(parent, ls), &i);
			if (ft_strchr(ls->options, 'x') != NULL)
				ft_putchar('\n');
			if (ft_strchr(ls->options, 'R') != NULL)
				get_dir(parent->sub, ls);
			free_files(parent->sub);
		}
	}
	else
		ft_error_ls(strerror(errno), parent->name);
}
