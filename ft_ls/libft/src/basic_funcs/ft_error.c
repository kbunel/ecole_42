/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 17:48:18 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/20 17:30:35 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void		ft_error(char *txt, int ligne)
{
	if (ligne > 0)
		ft_printf("%fLigne %d: %s.\n", 2, ligne, txt);
	else
		ft_printf("%f%s\n", 2, txt);
	exit(EXIT_FAILURE);
}
