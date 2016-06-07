/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 19:54:46 by kbunel            #+#    #+#             */
/*   Updated: 2015/12/07 16:28:29 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	struct s_list		*str;
	void				*ct;

	if ((str = (t_list *)malloc(sizeof(t_list))))
	{
		if (content != NULL)
		{
			ct = (void *)malloc(sizeof(void *) * content_size);
			ct = ft_memcpy(ct, content, content_size);
			str->content = ct;
			str->content_size = content_size;
		}
		else
		{
			str->content = NULL;
			str->content_size = 0;
		}
		str->next = NULL;
		return (str);
	}
	else
		return (NULL);
}
