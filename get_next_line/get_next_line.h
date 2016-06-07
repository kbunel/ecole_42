/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 18:41:34 by kbunel            #+#    #+#             */
/*   Updated: 2016/02/18 13:07:55 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 10

# include "libft/libft.h"

typedef	struct			s_gnl
{
	char				*buf;
	char				*tmp1;
	char				*tmp2;
	int					i;
	int					fd;
	int					in;
	int					r;
	struct s_gnl		*prev;
	struct s_gnl		*next;
}						t_gnl;

int						get_next_line(int const fd, char **line);

#endif
