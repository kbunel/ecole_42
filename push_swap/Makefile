# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbunel <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/09 18:43:21 by kbunel            #+#    #+#              #
#    Updated: 2016/03/22 19:29:36 by kbunel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

FONCTIONS = ft_check_lwf.c ft_pa_pb.c ft_check_valid_nb.c ft_ra_rb.c \
			ft_disp_arg_count.c ft_rra_rrb.c ft_disp_cmd.c ft_sa_sb.c \
			ft_disp_line.c ft_error_msg.c main.c ft_functions_ia.c \
			ft_get_func.c ft_atoi_push_swap.c ft_ia.c ft_check_fwl.c ft_init.c

HEADER = push_swap.h

HEADER_LIB = libft/libft.h

OBJ = $(FONCTIONS:.c=.o)

FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	make -C libft/
	/usr/bin/gcc $(FLAG) -c $(FONCTIONS) $(FONCTIONS_LIB) -I $(HEADER)
	/usr/bin/gcc $(FLAG) -o $(NAME) $(OBJ) $(OBJ_O_LIB) -L libft/ -lft

clean:
	/bin/rm -f $(OBJ)
	make clean -C libft/

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C libft/

re: fclean
	make
