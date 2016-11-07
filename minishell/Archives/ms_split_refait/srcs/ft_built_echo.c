/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 13:53:25 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/29 17:23:25 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int				b_echo(char **args)
{
	int		i;

	i = 1;
	while (args[i] != NULL)
	{
		ft_putstr(args[i]);
		if (args[++i] != NULL)
			ft_putchar(' ');
	}
	ft_putchar('\n');
	return (1);
}
