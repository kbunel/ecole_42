/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 23:57:26 by kbunel            #+#    #+#             */
/*   Updated: 2016/03/31 19:32:15 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	ft_error(int error)
{
	ft_putstr("\033[31m");
	if (error == 0)
		ft_putendl("ERROR");
	else if (error == 1)
		ft_putendl("Wrong number of ants");
	else if (error == 4)
		ft_putendl("Error Malloc");
	else
		ft_putendl("ERROR");
	ft_putstr("\033[0m");
	exit(1);
}
