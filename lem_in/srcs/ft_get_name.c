/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_name.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 23:02:50 by kbunel            #+#    #+#             */
/*   Updated: 2016/03/31 18:52:23 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

char			*ft_get_name(char *line, int kind, int r)
{
	int		i;

	i = 0;
	while (line[i] != ' ' && line[i] != '-')
		i++;
	if (kind == room)
		return (ft_strsub(line, 0, i));
	else if (kind == way && r == 0)
		return (ft_strsub(line, 0, i));
	else
		return (ft_strsub(line, i + 1, ft_strlen(line) - i));
}
