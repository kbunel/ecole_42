/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 12:58:22 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/22 18:34:14 by kbunel           ###   ########.fr       */
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

static void		ft_print_name_else(t_file *file, t_ls *ls)
{
	if (ft_strchr(ls->options, 'G') != NULL)
	{
		if (S_ISREG(file->type) && (is_exec(file->type)))
			ft_printf("{red}%s{eoc}\n", file->name);
		else if (S_ISDIR(file->type))
			ft_printf("{cyan}%s{eoc}\n", file->name);
		else if (S_ISBLK(file->type))
			ft_printf("{blue}%s{eoc}\n", file->name);
		else if (S_ISCHR(file->type))
			ft_printf("{green}%s{eoc}\n", file->name);
		else if (S_ISFIFO(file->type))
			ft_printf("{pink}%s{eoc}\n", file->name);
		else if (S_ISLNK(file->type))
			ft_printf("{yellow}%s{eoc}\n", file->name);
		else if (S_ISSOCK(file->type))
			ft_printf("{red}%s{eoc}\n", file->name);
		else
			ft_printf("%s\n", file->name);
	}
	else
		ft_printf("%s\n", file->name);
}

void			ft_print_name(t_file *file, char *fleche, t_ls *ls)
{
	if (S_ISLNK(file->type) && ft_strchr(ls->options, 'G') != NULL)
		ft_printf("{pink}%s{eoc} %s %s\n", file->name, fleche, file->l_path);
	else if (S_ISLNK(file->type))
		ft_printf("%s %s %s\n", file->name, fleche, file->l_path);
	else
		ft_print_name_else(file, ls);
}
