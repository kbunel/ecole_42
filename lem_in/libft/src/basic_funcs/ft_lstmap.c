/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 01:14:51 by kbunel            #+#    #+#             */
/*   Updated: 2016/03/23 16:05:59 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*list_browser;

	new_list = f(ft_lstnew(lst->content, lst->content_size));
	list_browser = new_list;
	while (lst->next != NULL)
	{
		new_list->next = f(lst->next);
		new_list = new_list->next;
		lst = lst->next;
	}
	return (list_browser);
}
