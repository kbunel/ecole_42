/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 13:20:40 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/13 15:30:53 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_dir(char *dir_name)
{
	DIR				*directory;
	struct dirent	*dp;

	directory = (dir_name != NULL) ? opendir(dir_name) : opendir(".");
	while ((dp = readdir(directory)) != NULL)
		ft_printf("%-10s", dp->d_name);
	ft_putchar('\n');
}
