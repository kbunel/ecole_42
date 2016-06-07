# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgerboui <tgerboui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/18 17:11:12 by tgerboui          #+#    #+#              #
#    Updated: 2016/06/07 16:31:15 by kbunel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = ft_bzero.c \
	ft_check_new.c \
	ft_count.c \
	ft_create_map.c \
	ft_exit.c \
	ft_getelem.c \
	ft_lstgetelem.c \
	ft_memalloc.c \
	ft_memset.c \
	ft_putstr.c \
	ft_size_min_map.c \
	ft_solve_it_2.c \
	ft_strlen.c \
	ft_strsplit.c \
	ft_strsub.c \
	ft_true_tetri.c \
	ft_wordlen.c \
	main.c \

HEADER = lib_fillit.h

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRC)
	gcc $(FLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean
	make
