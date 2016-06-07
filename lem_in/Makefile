# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbunel <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/30 15:24:53 by kbunel            #+#    #+#              #
#    Updated: 2016/03/31 21:08:24 by kbunel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC_NAME = ft_check_file.c ft_get_file.c ft_init.c ft_error.c \
		   ft_get_new_room.c main.c ft_sh_path.c ft_get_name.c \
		   ft_check_new_way.c ft_free.c ft_check_datas.c \
		   ft_get_paths.c

OBJ_NAME = $(SRC_NAME:.c=.o)

HEADER_NAME = lemin.h

SRC_PATH = srcs

OBJ_PATH = obj

INC = includes

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

HEAD = $(addprefix $(INC)/,$(HEADER_NAME))

CC = clang

CFLAGS = -Wall -Werror -Wextra

CPPFLAGS = -Iincludes

LDFLAGS = -Llibft

LDLIBS = -lft

.PHONY: all, clean, fclean, re
	
all: $(NAME)

$(NAME): $(OBJ) libft/libft.a
	@echo "  Compiling $@"
	@$(CC) $(LDFLAGS) $(LDLIBS) $(OBJ) -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@echo "  Compiling $@"
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
	
clean:
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@make clean -C libft/

libft/libft.a:
	@echo "  Making Libft"
	@make -C libft/

fclean:	clean
	@rm -f $(NAME)
	@make fclean -C libft/

re:	fclean all

norm:
	@norminette $(SRC) | grep -v Norme -B1 || true
	@norminette $(HEAD) | grep -v Norme -B1 || true
	@make norm -C libft/
