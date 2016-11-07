/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_ms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 19:45:45 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/27 20:05:54 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		ft_error_ms(int error, char *txt)
{
	if (error == CMDNOTFOUND)
		ft_printf("%fminishell: command not found: %s\n", 2, txt);
}
