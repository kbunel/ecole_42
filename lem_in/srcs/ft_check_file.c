/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 23:56:51 by kbunel            #+#    #+#             */
/*   Updated: 2016/03/31 11:19:51 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static int			ft_check_way(char *line, t_lm *lm)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	lm->infos = way;
	while (j < 2)
	{
		while (line[i] != '-' && line[i] != '\0')
			i++;
		if (j == 0 && line[i] == '-')
			i++;
		else if (j == 0 && line[i] != '-')
			return (0);
		j++;
	}
	if (line[i] != '\0')
		return (0);
	else
		return (1);
}

int					ft_check_room(char *line, t_lm *lm, int r)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (lm->infos == room && j < 3)
	{
		if (j < 1)
			while (line[i] != ' ' && line[i] != '\0')
				i++;
		else
			while (ft_isdigit(line[i]) == 1)
				i++;
		if (j < 2 && line[i] == ' ')
			i++;
		else if (j < 2 && line[i] != ' ')
			break ;
		j++;
	}
	if ((line[i] != '\0' || j < 2) && r == room)
		return (0);
	if (line[i] != '\0' || j < 2)
		return (ft_check_way(line, lm));
	return (1);
}

int					ft_check_comment(char *line, t_lm *lm, int l)
{
	if (line[1] == '#' && ft_strcmp(line, "##start") == 0 && lm->start != -1)
		return (0);
	else if (line[1] == '#' && ft_strcmp(line, "##end") == 0 && lm->end != -1)
		return (0);
	else if (line[1] == '#' && ft_strcmp(line, "##start") == 0)
		lm->start = l;
	else if (line[1] == '#' && ft_strcmp(line, "##end") == 0)
		lm->end = l;
	return (1);
}
