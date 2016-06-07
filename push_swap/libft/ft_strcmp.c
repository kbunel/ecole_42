/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:20:07 by kbunel            #+#    #+#             */
/*   Updated: 2015/12/01 16:19:11 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;
	int		a;
	int		b;

	i = 0;
	while (s1[i] == s2[i]
			&& s1[i] != '\0'
			&& s2[i] != 0)
		i++;
	a = ((unsigned char)s1[i]);
	b = ((unsigned char)s2[i]);
	return (a - b);
}
