/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_l.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 19:37:28 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/22 18:34:14 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static char		get_right(mode_t st_mode, int s)
{
	if (s == 1 && (st_mode & S_ISUID))
		return ((st_mode & S_IXUSR) ? 's' : 'S');
	else if (s == 2 && (st_mode & S_ISGID))
		return ((st_mode & S_IXGRP) ? 's' : 'S');
	else if (s == 3 && (st_mode & S_ISVTX))
		return ((st_mode & S_IXGRP) ? 't' : 'T');
	else if (s == 1)
		return ((st_mode & S_IXUSR) ? 'x' : '-');
	else if (s == 2)
		return ((st_mode & S_IXGRP) ? 'x' : '-');
	else if (s == 3)
		return ((st_mode & S_IXOTH) ? 'x' : '-');
	return ('\0');
}

static void		print_type_f_perm(mode_t st_mode)
{
	char	t;

	t = '\0';
	if (S_ISBLK(st_mode))
		t = 'b';
	else if (S_ISCHR(st_mode))
		t = 'c';
	else if (S_ISDIR(st_mode))
		t = 'd';
	else if (S_ISFIFO(st_mode))
		t = 'p';
	else if (S_ISREG(st_mode))
		t = '-';
	else if (S_ISLNK(st_mode))
		t = 'l';
	else if (S_ISSOCK(st_mode))
		t = 's';
	ft_printf("%c%c%c%c%c%c%c%c%c%c", t, (st_mode & S_IRUSR) ? 'r' : '-',
			(st_mode & S_IWUSR) ? 'w' : '-', get_right(st_mode, 1),
			(st_mode & S_IRGRP) ? 'r' : '-', (st_mode & S_IWGRP) ? 'w' : '-',
			get_right(st_mode, 2), (st_mode & S_IROTH) ? 'r' : '-',
			(st_mode & S_IWOTH) ? 'w' : '-', get_right(st_mode, 3));
}

static char		get_acl(int listxattr, char *path)
{
	acl_t	acl;

	acl = acl_get_file(path, ACL_TYPE_EXTENDED);
	if (listxattr > 0)
	{
		acl_free((void *)acl);
		return ('@');
	}
	else if (acl)
	{
		acl_free((void *)acl);
		return ('+');
	}
	acl_free((void *)acl);
	return (' ');
}

static void		print_long(t_file *file, int c_disp, char acl, t_ls *ls)
{
	char			*fleche;

	fleche = (S_ISLNK(file->type)) ? ft_strdup("->") : ft_strdup("\0");
	if (ft_strchr(ls->options, 'g') != NULL)
	{
		ft_bzero(file->pw_name, ft_strlen(file->pw_name));
		file->parent->s_o_len = -2;
	}
	ft_print_l_mid(file, acl, c_disp, ls);
	ft_print_name(file, fleche, ls);
	ft_memdel((void **)&fleche);
}

void			print_file_l(t_file *file, t_ls *ls)
{
	struct stat		f_stat;
	char			acl;
	int				c_disp;

	if (lstat(file->path, &f_stat) != -1)
	{
		lstat(file->path, &f_stat);
		acl = get_acl(file->listxattr, file->path);
		print_type_f_perm(f_stat.st_mode);
		c_disp = (file->parent->c_disp == 1) ? 4 : 0;
		print_long(file, c_disp, acl, ls);
	}
	else
		ft_error_ls(strerror(errno), file->name);
}
