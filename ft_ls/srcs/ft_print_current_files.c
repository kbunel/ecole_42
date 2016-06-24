/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_current_files.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 13:05:12 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/23 13:27:05 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int		is_exec(mode_t st_mode)
{
	if ((st_mode & S_IXUSR) || (st_mode & S_IXGRP) || (st_mode & S_IXOTH))
		return (1);
	else
		return (0);
}

static void		get_len(t_file *file, t_ls *ls, int *len)
{
	*len = (file->parent != NULL) ? file->parent->sub_len + 2 :
		ft_strlen(file->name) + 2;
	if (ft_strchr(ls->options, '1') != NULL)
		*len = ft_strlen(file->name);
}

void			print_file(t_file *file, t_ls *ls)
{
	int		len;

	get_len(file, ls, &len);
	if (ft_strchr(ls->options, 'G') != NULL)
	{
		if (S_ISREG(file->type) && (is_exec(file->type)))
			ft_printf("{red}%-*s{eoc}", len, file->name);
		else if (S_ISDIR(file->type))
			ft_printf("{cyan}%-*s{eoc}", len, file->name);
		else if (S_ISBLK(file->type))
			ft_printf("{blue}%-*s{eoc}", len, file->name);
		else if (S_ISCHR(file->type))
			ft_printf("{green}%-*s{eoc}", len, file->name);
		else if (S_ISFIFO(file->type))
			ft_printf("{yellow}%-*s{eoc}", len, file->name);
		else if (S_ISLNK(file->type))
			ft_printf("{pink}%-*s{eoc}", len, file->name);
		else if (S_ISSOCK(file->type))
			ft_printf("{red}%-*s{eoc}", len, file->name);
		else
			ft_printf("%-*s", len, file->name);
	}
	else
		ft_printf("%-*s", len, file->name);
}

void			print_parent_path(char *path, t_ls *ls, t_file *parent)
{
	char	*rot_path;

	if (parent != NULL && ((ft_strcmp(parent->name, ".") != 0
		&& ft_strcmp(parent->name, ls->args->name) != 0)
				|| ls->nb_args > 1))
	{
		if (ls->files != parent || ls->w_reg-- == 1)
			ft_putchar('\n');
		if (ft_strlen(path) > 0 && path[ft_strlen(path) - 1] == '/'
				&& ft_strcmp(path, "/") != 0 && parent->argu == 0)
		{
			rot_path = ft_strsub(path, 0, ft_strlen(path) - 1);
			if (ft_strchr(ls->options, 'G') != NULL)
				ft_printf("{cyan}%s:{eoc}\n", rot_path);
			else
				ft_printf("%s:\n", rot_path);
			ft_memdel((void **)&rot_path);
		}
		else
			(ft_strchr(ls->options, 'G') != NULL) ?
				ft_printf("{cyan}%s:{eoc}\n", path) :
				ft_printf("%s:\n", path);
	}
}
