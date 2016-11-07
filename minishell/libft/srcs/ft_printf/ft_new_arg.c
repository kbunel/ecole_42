/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 18:49:56 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/13 15:30:54 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

t_arg		*ft_new_arg(t_arg *prev_arg)
{
	t_arg	*arg;

	if (prev_arg->value == NULL)
		return (prev_arg);
	if ((arg = (t_arg *)malloc(sizeof(t_arg))))
	{
		prev_arg->next = arg;
		arg->next = NULL;
	}
	else
		ft_error_msg(0, NULL, 0, 0);
	return (arg);
}
