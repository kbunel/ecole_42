/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_stat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 13:02:46 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/24 18:33:54 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void			init_time(t_file *new_file, t_ls *ls, struct stat f_stat)
{
	new_file->mtimespec = (ft_strchr(ls->options, 'u') == NULL) ?
		ft_strsub(ctime(&f_stat.st_mtimespec.tv_sec), 4, 6) : NULL;
	new_file->atimespec = (ft_strchr(ls->options, 'u') != NULL) ?
		ft_strsub(ctime(&f_stat.st_atimespec.tv_sec), 4, 6) : NULL;
	new_file->ntimespec = f_stat.st_mtimespec.tv_sec;
	new_file->natimespec = f_stat.st_atimespec.tv_sec;
	new_file->nntimespec = f_stat.st_mtimespec.tv_nsec;
	new_file->nnatimespec = f_stat.st_atimespec.tv_nsec;
}

static void			get_time(t_file *new_file, struct stat f_stat, t_ls *ls)
{
	time_t			now;

	now = 0;
	new_file->stat_time = 1;
	time(&now);
	init_time(new_file, ls, f_stat);
	if ((ft_strchr(ls->options, 'u') == NULL
		&& f_stat.st_mtimespec.tv_sec < now - 60 * 60 * 24 * 31 * 6)
		|| (ft_strchr(ls->options, 'u') != NULL
		&& f_stat.st_atimespec.tv_sec < now - 60 * 60 * 24 * 31 * 6)
		|| f_stat.st_mtimespec.tv_sec > now)
	{
		new_file->hour_year = (ft_strchr(ls->options, 'u') == NULL) ?
			ft_strsub(ctime(&f_stat.st_mtimespec.tv_sec), 19, 5) : NULL;
		new_file->a_hour_year = (ft_strchr(ls->options, 'u') != NULL) ?
			ft_strsub(ctime(&f_stat.st_atimespec.tv_sec), 19, 5) : NULL;
	}
	else
	{
		new_file->hour_year = (ft_strchr(ls->options, 'u') == NULL) ?
			ft_strsub(ctime(&f_stat.st_mtimespec.tv_sec), 11, 5) : NULL;
		new_file->a_hour_year = (ft_strchr(ls->options, 'u') != NULL) ?
			ft_strsub(ctime(&f_stat.st_atimespec.tv_sec), 11, 5) : NULL;
	}
}

static void			get_stat(t_file *new_file, struct stat f_stat,
		t_file *parent, t_ls *ls)
{
	new_file->stat = 1;
	new_file->links = f_stat.st_nlink;
	new_file->pw_name = (getpwuid(f_stat.st_uid) != NULL) ?
		ft_strdup(getpwuid(f_stat.st_uid)->pw_name) :
		ft_itoa(f_stat.st_uid);
	new_file->gr_name = (getgrgid(f_stat.st_gid) != NULL) ?
		ft_strdup(getgrgid(f_stat.st_gid)->gr_name) :
		ft_itoa(f_stat.st_gid);
	new_file->size = f_stat.st_size;
	get_time(new_file, f_stat, ls);
	if (parent != NULL)
		new_file->parent->blocks += f_stat.st_blocks;
	if (S_ISLNK(new_file->type))
	{
		new_file->l_path = ft_memalloc(2048);
		readlink(new_file->path, new_file->l_path, 2048);
	}
	else
		new_file->l_path = NULL;
	if (S_ISLNK(new_file->type))
		new_file->listxattr = listxattr(new_file->path, NULL, 0,
				XATTR_NOFOLLOW);
	else
		new_file->listxattr = listxattr(new_file->path, NULL, 0, 0);
}

static void			init_stat_null(t_file *new_file, t_ls *ls)
{
	struct stat		f_stat;

	new_file->links = 0;
	new_file->pw_name = NULL;
	new_file->gr_name = NULL;
	new_file->size = 0;
	if (ft_strchr(ls->options, 't') != NULL)
	{
		lstat(new_file->path, &f_stat);
		get_time(new_file, f_stat, ls);
	}
	else
	{
		new_file->mtimespec = NULL;
		new_file->atimespec = NULL;
		new_file->hour_year = NULL;
		new_file->a_hour_year = NULL;
		new_file->ntimespec = 0;
		new_file->atimespec = 0;
		new_file->nntimespec = 0;
		new_file->nnatimespec = 0;
	}
	new_file->listxattr = 0;
	new_file->l_path = NULL;
}

void				ft_get_stat(t_file *new_file, t_file *parent,
		char *name, t_ls *ls)
{
	struct stat		f_stat;

	if ((ft_strchr(ls->options, 'l') != NULL && parent != NULL
					&& lstat(new_file->path, &f_stat) != -1)
			|| (parent == ls->empty_file && lstat(name, &f_stat) != -1))
		get_stat(new_file, f_stat, parent, ls);
	else
		init_stat_null(new_file, ls);
}
