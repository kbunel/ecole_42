/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:47:41 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/13 15:30:45 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		n;
	int		a;

	i = 0;
	a = 0;
	n = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		i++;
		n = -1;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		a = (a * 10) + (str[i] - 48) % 10;
		i++;
	}
	return (a *= n);
}
