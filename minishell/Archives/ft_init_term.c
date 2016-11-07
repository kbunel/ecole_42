/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_term.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 15:31:53 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/28 16:00:23 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void			ft_init_term(void)
{
	struct termios		termios;

	tcgetattr(1, &termios);
	//termios.c_lflag &= ~(ICANON);
	termios.c_lflag &= ~(ECHO);
	termios.c_cc[VMIN] = 1;
	termios.c_cc[VTIME] = 0;
	tcsetattr(1, TCSADRAIN, &termios);
}

void			ft_reinit_term(void)
{
	struct termios		termios;

	tcgetattr(1, &termios);
	termios.c_lflag = (ICANON | ECHO);
	tcsetattr(1, 0, &termios);
}
