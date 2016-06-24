# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbunel <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/30 15:24:53 by kbunel            #+#    #+#              #
#    Updated: 2016/06/24 17:34:02 by kbunel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC_NAME = main.c ft_init_free.c ft_sort.c ft_get_stat.c ft_get_arg.c \
	   ft_error_ls.c ft_get_files_r.c ft_print_current_files.c \
	   ft_new_file.c ft_sort_reverse.c ft_get_len.c ft_print_l.c \
	   ft_sort_time.c ft_get_sort.c ft_init_files.c ft_print_arg.c \
	   ft_get_files_init.c ft_new_empty_file.c ft_print_name.c \
	   ft_sort_time_last_access.c ft_print_l_mid.c ft_put_file.c \
	   ft_print_binary_three.c ft_put_last_modif.c ft_put_last_access.c \
	   ft_put_last_modif_reverse.c ft_put_last_access_reverse.c

OBJ_NAME = $(SRC_NAME:.c=.o)

HEADER_NAME = ft_ls.h

SRC_PATH = srcs

OBJ_PATH = obj

INC = includes

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

HEAD = $(addprefix $(INC)/,$(HEADER_NAME))

CC = clang

CFLAGS = -Wall -Werror -Wextra -g

CPPFLAGS = -I includes

LDFLAGS = -L libft/

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
