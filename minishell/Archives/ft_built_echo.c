/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 13:53:25 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/30 11:55:41 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void		check_quote(char *line, int *q)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
		if (line[i++] == '\'')
			*q = ~*q;
	ft_printf("binaire: %b, decimal: %d", *q, *q);
}

static char		*get_line_quote(int	*q)
{
	char		*line;
	char		*str;
	int			i;
	int			j;

	i = 0;
	j = 0;
	line = NULL;
	ft_putstr("quote> ");
	get_next_line(1, &line);
	str = ft_memalloc(ft_strlen(line));
	while (line[i] != '\0')
	{
		if (line[i] != '\'')
			str[j++] = line[i++];
		else
		{
			*q = ~*q;
			i++;
		}
	}
	return (str);
}

int				b_echo(char *line)
{
	char		**str;
	int				i;
	int				j;
	int				q;

	i = 5;
	j = 0;
	q = 0b0;
	str = (char **)malloc(sizeof(char));
	str[0] = ft_memalloc(ft_strlen(line));
	check_quote(line, &q);
	while (line[i] != '\0')
	{
		if (line[i] != '\'')
			str[0][j++] = line[i++];
		else
			i++;
	}
	i = 1;
	while ((q & 1))
		str[i++] = get_line_quote(&q);
	str[i] = NULL;
	i = 0;
	while (str[i] != NULL)
	{
		ft_putstr(str[i]);
		ft_memdel((void **)&str[i++]);
	}
	ft_memdel((void **)&str);
	ft_putchar('\n');
	return (1);
}
