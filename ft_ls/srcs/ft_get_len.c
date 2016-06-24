/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 14:31:48 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/22 18:34:14 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		get_lens(t_file *file)
{
	int		len;

	if (file->stat == 1)
	{
		len = ft_strlen(file->pw_name);
		if (len > file->parent->s_o_len)
			file->parent->s_o_len = len;
		len = ft_strlen(file->gr_name);
		if (len > file->parent->s_g_len)
			file->parent->s_g_len = len;
		len = ft_strleni(file->size);
		if (len > file->parent->s_size_len)
			file->parent->s_size_len = len;
		len = ft_strleni(file->links);
		if (len > file->parent->s_l_len)
			file->parent->s_l_len = len;
	}
	len = ft_strlen(file->name);
	if (len > file->parent->sub_len)
		file->parent->sub_len = len;
}
