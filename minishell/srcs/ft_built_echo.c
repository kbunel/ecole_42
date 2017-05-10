/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 13:53:25 by kbunel            #+#    #+#             */
/*   Updated: 2017/05/10 20:28:49 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int					check_if_quote(char **args, char *str, char quote)
{
	int		i;
	int		q;

	q = 0;
	i = 0;
	if (args != NULL)
	{
		while (args[i])
			if ((ft_strcchr(args[i++], quote) & 1) != 0)
				q++;
	}
	if (str != NULL && (ft_strcchr(str, quote) & 1) != 0)
		q++;
	if ((q & 1) != 0)
		return (1);
	else
		return (0);
}

static t_quote		*get_new_text(char *str)
{
	t_quote		*new_text;

	new_text = (t_quote *)malloc(sizeof(t_quote));
	new_text->str = ft_strdup(str);
	new_text->next = NULL;
	return (new_text);
}

static t_quote		*get_quote(char quote)
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
	while (check_if_quote(NULL, text->str, quote) == 0)
	{
		ft_putstr("quote> ");
		get_next_line(1, &line);
		text->next = get_new_text(line);
		text = text->next;
		free(line);
	}
	text->str[ft_strlen(text->str) - 1] = '\0';
	return (first);
}

static void			write_quote(t_quote *text)
{
	t_quote		*g_text;

	g_text = NULL;
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
}

int					b_echo(char **args)
{
	int			i;
	t_quote		*text;
	char		quote;

	i = 0;
	text = NULL;
	quote = ft_kind_quote(args);
	if (quote != '\0')
		text = get_quote(quote);
	i = 1;
	while (args[i] != NULL)
	{
		if (args[i][ft_strlen(args[i]) - 1] == quote)
			args[i][ft_strlen(args[i]) - 1] = '\0';
		ft_putstr(args[i] + (quote != '\0' && args[i][0] == quote ? 1 : 0));
		if (args[i++ + 1] != NULL)
			ft_putchar(' ');
	}
	i = 0;
	write_quote(text);
	ft_putchar('\n');
	return (1);
}
