/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 12:43:28 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/24 17:41:40 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		init_sub_file(struct dirent *dp, char *path,
		t_file *new_file)
{
	char		*tmp;

	new_file->name = ft_strdup(dp->d_name);
	new_file->namlen = dp->d_namlen;
	if (ft_strlen(path) > 0 && path[ft_strlen(path) - 1] != '/')
	{
		tmp = ft_strjoin(path, "/");
		new_file->path = ft_strjoin(tmp, dp->d_name);
		ft_memdel((void **)&tmp);
	}
	else
		new_file->path = ft_strjoin(path, dp->d_name);
	new_file->parent->nb_sub++;
}

static void		init_p_file(char *name, t_file *new_file)
{
	new_file->name = ft_strdup(name);
	new_file->namlen = ft_strlen(name);
	new_file->path = ft_strdup(name);
}

static void		init_basic(t_file *new_file, t_file *parent)
{
	new_file->parent = parent;
	new_file->nb_sub = 0;
	new_file->c_disp = 0;
	new_file->blocks = 0;
	new_file->sub = NULL;
	new_file->next = NULL;
	new_file->sub_len = 14;
	new_file->s_o_len = 0;
	new_file->s_g_len = 0;
	new_file->s_l_len = 1;
	new_file->s_size_len = 1;
	new_file->argu = 0;
	new_file->stat = 0;
	new_file->stat_time = 0;
}

t_file			*init_file(struct dirent *dp, t_file *parent, char *path,
		char *name)
{
	t_file			*new_file;
	struct stat		f_stat;

	if (!(new_file = (t_file *)malloc(sizeof(t_file))))
		ft_error(strerror(errno), 0);
	init_basic(new_file, parent);
	(dp != NULL) ? init_sub_file(dp, path, new_file) :
		init_p_file(name, new_file);
	if ((dp != NULL && lstat(new_file->path, &f_stat) != -1)
			|| (dp == NULL && lstat(name, &f_stat) != -1))
		new_file->type = f_stat.st_mode;
	else
		new_file->type = 0;
	if ((S_ISCHR(new_file->type)) || S_ISBLK(new_file->type))
		new_file->parent->c_disp = 1;
	new_file->major = (S_ISCHR(new_file->type) || S_ISBLK(new_file->type)) ?
		major(f_stat.st_rdev) : 0;
	new_file->minor = (S_ISCHR(new_file->type) || S_ISBLK(new_file->type)) ?
		minor(f_stat.st_rdev) : 0;
	return (new_file);
}
