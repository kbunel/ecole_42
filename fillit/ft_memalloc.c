/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 01:16:49 by kbunel            #+#    #+#             */
/*   Updated: 2015/12/10 18:37:11 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_fillit.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;

	if ((mem = malloc(size)))
	{
		ft_bzero(mem, size);
		return (mem);
	}
	else
		return (NULL);
}
