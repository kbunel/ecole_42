/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:52:09 by kbunel            #+#    #+#             */
/*   Updated: 2016/03/22 19:08:50 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_error(int error)
{
	if (error == 1)
		ft_putendl("\033[1;31mError\033[0m");
	else if (error == 2)
	{
		ft_putendl("\n\033[1;31m	Option unavailabe, select option below:\n");
		ft_putendl("\033[36m-v	Display operation running\n");
		ft_putendl("-c 	Display Command during operations\n");
		ft_putendl("-m	Silence commands at the end of operations\n");
		ft_putendl("-l	Display lines and number of operations at the end\n");
		ft_putendl("-a	Display the details of operations\033[0m\n");
	}
	else if (error == 3)
		ft_putendl("\033[1;31mPlease insert a list of numbers.\033[0m");
	else if (error == 3)
		ft_putendl("\033[1;31mError Malloc.\033[0m");
	exit(1);
}
