/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aoi_ll.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 14:03:03 by kbunel            #+#    #+#             */
/*   Updated: 2016/03/23 16:05:59 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

long long		ft_atoi_ll(const char *str)
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
