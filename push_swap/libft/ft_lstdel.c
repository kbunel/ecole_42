/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 22:40:12 by kbunel            #+#    #+#             */
/*   Updated: 2015/12/07 14:56:19 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	while (alst[0])
	{
		del(alst[0]->content, alst[0]->content_size);
		free(alst[0]);
		alst[0] = alst[0]->next;
	}
	alst = NULL;
}
