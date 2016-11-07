/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 13:53:25 by kbunel            #+#    #+#             */
/*   Updated: 2016/10/04 23:45:21 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int		check_quote(char **args, char *str)
{
	int		i;
	int		q;

	q = 0;
	i = 0;
	if (args != NULL)
	{
		while(args[i])
			if ((ft_strcchr(args[i++], '\'') & 1) != 0)
				q++;
	}
	if (str != NULL && (ft_strcchr(str, '\'') & 1) != 0)
		q++;
	if ((q & 1) != 0)
		return (1);
	else
		return (0);
}

static t_quote	*get_new_text(char *str)
{
	t_quote		*new_text;

	new_text = (t_quote *)malloc(sizeof(t_quote));
	new_text->str = ft_strdup(str);
	new_text->next = NULL;
	return (new_text);
}

static t_quote		*get_quote()
{
	char		*line;
	int			i;
	t_quote		*text;
	t_quote		*first;

	i = 0;
	ft_putstr("quote> ");
	get_next_line(1, &line);
	text = get_new_text(line);
	first = text;
	free(line);
	while (check_quote(NULL, text->str) == 0)
	{
		ft_putstr("quote> ");
		get_next_line(1, &line);
		text->next = get_new_text(line);
		text = text->next;
		free(line);
	}
	return (first);
}

int				b_echo(char **args)
{
	int			i;
	t_quote		*text;
	t_quote		*g_text;

	i = 1;
	text = NULL;
	g_text = NULL;
	if (check_quote(args, NULL) == 1)
		text = get_quote();
	while (args[i] != NULL)
	{
		ft_putstr(args[i]);
		if (args[i++ + 1] != NULL)
			ft_putchar(' ');
	}
	i = 0;
	if (text != NULL)
		ft_putchar('\n');
	while (text != NULL)
	{
		ft_putstr(text->str);
		if (text->next != NULL)
			ft_putchar('\n');
		g_text = text;
		text = text->next;
		ft_memdel((void **)&g_text->str);
		ft_memdel((void **)&g_text);
	}
	ft_putchar('\n');
	return (1);
}
