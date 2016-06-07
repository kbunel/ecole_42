/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_ret.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 13:21:51 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/02 13:21:54 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_free_ret(void **ap)
{
	if (ap != NULL)
	{
		free(*ap);
		*ap = NULL;
		return (1);
	}
	else
		return (0);
}