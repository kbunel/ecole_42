/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 19:35:12 by kbunel            #+#    #+#             */
/*   Updated: 2016/03/23 17:48:36 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_gnl	*ft_new_l(t_gnl **l, int fd)
{
	t_gnl		*t;

	t = (t_gnl*)malloc(sizeof(t_gnl));
	t->i = 0;
	t->buf = NULL;
	t->next = NULL;
	t->prev = l[0];
	t->fd = fd;
	l[0]->next = t;
	return (t);
}

void	ft_init(t_gnl **l, char **buf, int fd)
{
	if (!(l[0]))
	{
		l[0] = (t_gnl*)malloc(sizeof(t_gnl));
		l[0]->buf = NULL;
		l[0]->next = NULL;
		l[0]->prev = NULL;
		l[0]->i = 0;
		l[0]->fd = fd;
	}
	else if (fd != l[0]->fd)
	{
		while (l[0]->prev != NULL)
			l[0] = l[0]->prev;
		while (l[0]->next != NULL)
			if (l[0]->fd == fd)
				break ;
			else
				l[0] = l[0]->next;
		if (l[0]->next == NULL && l[0]->fd != fd)
			l[0] = ft_new_l(&l[0], fd);
	}
	l[0]->in = 0;
	if (*buf != NULL)
		l[0]->buf = ft_strdup(*buf);
}

int		ft_content(char **line, t_gnl **l, int f1, int f2)
{
	if (f1 == 1)
	{
		l[0]->tmp2 = ft_strdup(line[0]);
		ft_memdel((void **)&line[0]);
		line[0] = ft_strjoin(l[0]->tmp2, l[0]->tmp1);
		ft_memdel((void **)&l[0]->tmp1);
		ft_memdel((void **)&l[0]->tmp2);
	}
	if (f2 == 1)
	{
		l[0]->i = ft_strichr(l[0]->buf, l[0]->i, '\n') + 1;
		if (l[0]->i >= (int)ft_strlen(l[0]->buf))
		{
			l[0]->i = 0;
			free(l[0]->buf);
			l[0]->buf = NULL;
		}
	}
	return (1);
}

int		ft_gnl(char **line, t_gnl **l)
{
	l[0]->in++;
	if (ft_strichr(l[0]->buf, l[0]->i, '\n') >= 0 && *line == NULL)
	{
		line[0] = ft_strsub(l[0]->buf, l[0]->i,
				ft_strichr(l[0]->buf, l[0]->i, '\n') - l[0]->i);
		ft_content(NULL, &l[0], 0, 1);
		return (1);
	}
	else if (*line == NULL && l[0]->i <= (int)ft_strlen(l[0]->buf))
		line[0] = ft_strsub(l[0]->buf, l[0]->i,
				ft_strlen(l[0]->buf) - l[0]->i);
	else if (line[0] != NULL && ft_strlen(line[0]) > 0
			&& ft_strichr(l[0]->buf, l[0]->i, '\n') >= 0
			&& (l[0]->tmp1 = ft_strsub(l[0]->buf, l[0]->i,
					ft_strichr(l[0]->buf, l[0]->i, '\n')))
			&& ft_content(&(*line), &l[0], 1, 1) == 1)
		return (1);
	else if (line[0] != NULL && ft_strlen(line[0]) > 0
			&& (l[0]->tmp1 = ft_strsub(l[0]->buf, l[0]->i,
				ft_strlen(l[0]->buf) - l[0]->i)))
		ft_content(&(*line), &l[0], 1, 0);
	l[0]->i = ft_strichr(l[0]->buf, l[0]->i, '\n') + 1;
	ft_memdel((void **)&l[0]->buf);
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	static t_gnl		*l;
	char				*buf;

	if (fd < 0 || line == NULL)
		return (-1);
	buf = NULL;
	*line = NULL;
	ft_init(&l, &buf, fd);
	if ((l->buf) && l->buf != NULL && ft_gnl(&line[0], &l) > 0)
		return (1);
	buf = ft_memalloc(BUFF_SIZE + 1);
	while ((l->r = read(l->fd, buf, BUFF_SIZE)))
	{
		if (l->r < 0)
			return (-1);
		ft_init(&l, &buf, l->fd);
		if (ft_gnl(&line[0], &l) > 0)
			return (1);
		ft_bzero(buf, ft_strlen(buf));
		l->in++;
		l->i = 0;
	}
	free(buf);
	l->in == 0 ? ft_memdel((void **)&line[0]) : NULL;
	return (l->in > 0 ? 1 : 0);
}
