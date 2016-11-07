/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:53:18 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/13 15:30:54 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void		ft_convert_uppercase(unsigned int n)
{
	if (n < 10)
		ft_putchar(n + 48);
	else if (n >= 10)
		ft_putchar(n + 55);
}

static	void	ft_convert_lowercase(unsigned int n)
{
	if (n < 10)
		ft_putchar(n + 48);
	else if (n >= 10)
		ft_putchar(n + 87);
}

void			ft_puthexa(unsigned int n, char x)
{
	if (n < 16 && x == 0)
		ft_convert_lowercase(n);
	else if (n < 16 && x == 1)
		ft_convert_uppercase(n);
	else if (n >= 16)
	{
		ft_puthexa(n / 16, x);
		ft_puthexa(n % 16, x);
	}
}
