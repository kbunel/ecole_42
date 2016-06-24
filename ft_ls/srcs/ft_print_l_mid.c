/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_l_mid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 16:16:21 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/23 12:50:44 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		print_chr_blk(t_file *file, t_ls *ls, int size_len, char acl)
{
	size_len -= (ft_strchr(ls->options, 'a') != NULL) ? 1 : 0;
	ft_printf("%c %*d %-*s%-*s%3d, %*d %s %s ", acl,
			file->parent->s_l_len, file->links, file->parent->s_o_len + 2,
			file->pw_name, file->parent->s_g_len + 2, file->gr_name,
			file->major, size_len, file->minor,
			(ft_strchr(ls->options, 'u') != NULL) ? file->atimespec :
			file->mtimespec, (ft_strchr(ls->options, 'u') != NULL) ?
			file->a_hour_year : file->hour_year);
}

static void		print_else(t_file *file, t_ls *ls, char acl, int c_disp)
{
	c_disp += (file->parent->s_size_len == 1) ? 3 : 0;
	ft_printf("%c %*d %-*s%-*s%*d %s %s ",
			acl, file->parent->s_l_len, file->links,
			file->parent->s_o_len + 2, file->pw_name,
			file->parent->s_g_len + 2, file->gr_name,
			file->parent->s_size_len + c_disp, file->size,
			(ft_strchr(ls->options, 'u') != NULL) ? file->atimespec :
			file->mtimespec, (ft_strchr(ls->options, 'u') != NULL) ?
			file->a_hour_year : file->hour_year);
}

void			ft_print_l_mid(t_file *file, char acl, int c_disp, t_ls *ls)
{
	int		size_len;

	size_len = (file->parent->s_size_len < 3) ? 3 : file->parent->s_size_len;
	if (S_ISCHR(file->type) || S_ISBLK(file->type))
		print_chr_blk(file, ls, size_len, acl);
	else
		print_else(file, ls, acl, c_disp);
}
