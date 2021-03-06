# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbunel <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/30 15:24:53 by kbunel            #+#    #+#              #
#    Updated: 2017/05/11 19:21:04 by kbunel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC_NAME = main.c ft_get_cmd.c ft_get_builtin.c ft_init_env.c ft_init_ms.c \
	ft_free_ms.c ft_error_ms.c ft_get_line.c ft_built_echo.c \
	ft_setenv.c ft_parse_line.c ft_built_cd.c \
	ft_get_shell_lvl.c ft_get_env.c ft_kind_quote.c ft_built_setenv.c

OBJ_NAME = $(SRC_NAME:.c=.o)

HEADER_NAME = minishell.h

SRC_PATH = srcs

OBJ_PATH = obj

INC = includes

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

HEAD = $(addprefix $(INC)/,$(HEADER_NAME))

CC = clang

CFLAGS = -Wall -Werror -Wextra

CPPFLAGS = -I includes

LDFLAGS = -L libft/

LDLIBS = -lft

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ) libft/libft.a
	@echo "  Compiling \033[32m$@\033[32m √\033[0m"
	@$(CC) $(LDFLAGS) $(LDLIBS) $(OBJ) -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@echo "  Compiling \033[36m$@\033[0m"
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@make clean -C libft/

libft/libft.a:
	@echo "  \033[32mMaking Libft\033[0m"
	@make -C libft/

fclean:	clean
	@rm -f $(NAME)
	@make fclean -C libft/

re:	fclean all

norm:
	@norminette $(SRC) | grep -v Norme -B1 || true
	@norminette $(HEAD) | grep -v Norme -B1 || true
	@make norm -C libft/
