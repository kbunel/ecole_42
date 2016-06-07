/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 13:37:14 by kbunel            #+#    #+#             */
/*   Updated: 2016/03/31 19:11:02 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static int			ft_get_room(char *line, t_lm *lm, int r)
{
	int		i;

	i = 1;
	if (r == start)
		i = ft_get_new_room(line, lm, start);
	else if (r == end)
		i = ft_get_new_room(line, lm, end);
	else if (r == room)
		i = ft_get_new_room(line, lm, room);
	else if (r == way)
		i = ft_get_new_way(line, lm);
	return (i);
}

static int			ft_get_ants(char *ants)
{
	int		i;

	i = 0;
	while (ants[i] != '\0')
		if (ft_isdigit(ants[i++]) == 0)
			ft_error(1);
	return (ft_atoi(ants));
}

static int			ft_get_map(t_lm *lm, char *line, int i)
{
	char	*ln;
	char	*map;

	if (i == 0)
	{
		free(line);
		return (0);
	}
	if (lm->map != NULL)
	{
		ln = ft_strdup(line);
		map = ft_strdup(lm->map);
		ft_memdel((void **)&lm->map);
		lm->map = ft_strjoin_free(map, ln);
	}
	else
		lm->map = ft_strdup(line);
	map = ft_strdup(lm->map);
	ft_memdel((void **)&lm->map);
	lm->map = ft_strjoin(map, "\n");
	ft_memdel((void **)&map);
	return (1);
}

void				ft_get_infos(t_lm *lm, int i, int l)
{
	char	*line;

	while (get_next_line(0, &line) != 0 && i == 1)
	{
		if (l > 0 && line[0] != '#' && ft_check_room(line, lm, way) == 0)
			break ;
		if (l == 0)
			lm->ants = ft_get_ants(line);
		else if (l > 0 && line[0] == '#')
			i = ft_check_comment(line, lm, l);
		else if (l == lm->start + 1)
			i = ft_get_room(line, lm, start);
		else if (l == lm->end + 1)
			i = ft_get_room(line, lm, end);
		else if (lm->infos == room)
			i = ft_get_room(line, lm, room);
		else if (lm->infos == way)
			i = ft_get_room(line, lm, way);
		else
			break ;
		l++;
		if (ft_get_map(lm, line, i) == 0)
			break ;
		free(line);
	}
}
