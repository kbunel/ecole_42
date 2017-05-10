/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kind_quote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 20:20:10 by kbunel            #+#    #+#             */
/*   Updated: 2017/05/10 20:29:20 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char		ft_kind_quote(char **args)
{
	char	quote;
	int		i;

	quote = '\0';
	i = 0;
	if (check_if_quote(args, NULL, '\'') == 1)
	{
		while (args[i] && ft_strcfirst(args[i], '\'') == -1 &&
				ft_strcfirst(args[i], '"') == -1)
			i++;
		quote = (check_if_quote(args, NULL, '"') == 1 &&
				ft_strcfirst(args[i], '"') >= 0 &&
				ft_strcfirst(args[i], '"') < ft_strcfirst(args[i], '\'') ?
				'"' : '\'');
	}
	else if (check_if_quote(args, NULL, '"') == 1)
		quote = '"';
	return (quote);
}
