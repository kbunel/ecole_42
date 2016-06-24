/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_empty_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 17:59:28 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/22 18:34:14 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void			init_empty(t_file *new_file)
{
	new_file->s_l_len = 1;
	new_file->s_size_len = 1;
	new_file->stat = 0;
	new_file->pw_name = NULL;
	new_file->gr_name = NULL;
	new_file->mtimespec = NULL;
	new_file->ntimespec = 0;
	new_file->nntimespec = 0;
	new_file->hour_year = NULL;
	new_file->size = 0;
	new_file->blocks = 0;
	new_file->listxattr = 0;
	new_file->c_disp = 0;
	new_file->l_path = NULL;
	new_file->major = 0;
	new_file->minor = 0;
	new_file->next = NULL;
	new_file->prev = NULL;
}

t_file				*new_empty_file(void)
{
	t_file		*new_file;

	new_file = (t_file *)malloc(sizeof(t_file));
	new_file->name = NULL;
	new_file->path = NULL;
	new_file->type = 0;
	new_file->namlen = 0;
	new_file->sub = NULL;
	new_file->nb_sub = 0;
	new_file->parent = NULL;
	new_file->links = 0;
	new_file->sub_len = 14;
	new_file->s_o_len = 0;
	new_file->s_g_len = 0;
	init_empty(new_file);
	return (new_file);
}
