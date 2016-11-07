/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aprse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 16:42:49 by kbunel            #+#    #+#             */
/*   Updated: 2016/09/26 22:31:16 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void		check_quote(char *line, int *q)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\'' || line[i] == '"')
			*q = ~*q;
		i++;
	}
}

static char		*get_line_quote(char *str, int *q)
{
	char	*line;
	char	*next;

	ft_putstr("quote> ");
	get_next_line(1, &line);
	check_quote(line, q);
	next = ft_strjoin(str, line);
	ft_memdel((void**)&line);
	return (next);
}

char			*get_cmds(char *line)
{
	int		q;
	char	*str;
	char	*tmp;

	q = 0;
	str = ft_strdup(line);
	check_quote(line, &q);
	while ((q & 1))
	{
		ft_check(1);
		tmp = get_line_quote(str, &q);
		ft_memdel((void **)&str);
		str = ft_strdup(tmp);
		ft_memdel((void **)&tmp);
	}
	return (str);
}
