/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlenint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 15:26:31 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/13 15:30:54 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_strleni(int nb)
{
	int			i;

	i = 1;
	if (nb < 10)
		return (1);
	else if (nb < 100)
		return (2);
	else if (nb < 1000)
		return (3);
	else if (nb < 10000)
		return (4);
	else if (nb < 100000)
		return (5);
	else if (nb < 1000000)
		return (6);
	else if (nb < 10000000)
		return (7);
	while (nb >= 10)
	{
		nb /= 10;
		i++;
	}
	return (i);
}
