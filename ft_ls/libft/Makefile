# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbunel <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/30 15:24:53 by kbunel            #+#    #+#              #
#    Updated: 2016/06/23 14:39:18 by kbunel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

F_BASICS = ft_isalnum.c ft_isprint.c ft_lstdelone.c ft_memalloc.c ft_memcpy.c \
			ft_putchar.c ft_putnbr.c ft_strcat.c ft_strcpy.c ft_strichr.c \
			ft_strlcat.c ft_strncat.c ft_strnew.c ft_strstr.c ft_toupper.c \
			ft_atoi.c ft_isalpha.c ft_itoa.c ft_lstiter.c ft_memccpy.c \
			ft_memdel.c ft_putchar_fd.c ft_putnbr_fd.c ft_strchr.c ft_strdel.c \
			ft_striter.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strsub.c \
			ft_wordlen.c ft_bzero.c ft_isascii.c ft_lstadd.c ft_lstmap.c \
			ft_memchr.c ft_memmove.c ft_putendl.c ft_putstr.c ft_strclr.c \
			ft_strdup.c ft_striteri.c ft_strmap.c ft_strncpy.c ft_strrchr.c \
			ft_strtrim.c ft_count.c	ft_isdigit.c ft_lstdel.c ft_lstnew.c \
			ft_memcmp.c ft_memset.c ft_putendl_fd.c ft_putstr_fd.c ft_strcmp.c \
			ft_strequ.c ft_strjoin.c ft_strmapi.c ft_strnequ.c ft_strsplit.c \
			ft_tolower.c ft_strisub.c ft_strjoin_free.c get_next_line.c \
			ft_check.c ft_free_ret.c ft_dir.c ft_error.c ft_strlenint.c

F_FT_PRINTF = ft_error_msg.c ft_itoa_printf_octal.c ft_itoa_printf_octal_j.c \
			ft_printf.c ft_get_w_string.c \
			ft_length.c	ft_get_wchar_t.c \
			ft_init.c ft_new_arg.c ft_init_d_i_len.c ft_print.c \
			ft_check_valid_param.c ft_itoa_printf.c ft_print_d_i.c ft_csfs.c \
			ft_itoa_printf_hexa.c ft_itoa_printf_ull.c ft_print_s.c \
			ft_itoa_printf_hexa_j.c ft_get_error_param.c ft_add_color.c \
			ft_print_n.c ft_get_length_b.c


HEADER_NAME = libft.h libftprintf.h

F_B_PATH = basic_funcs

F_PR_PATH = ft_printf

OBJ_PATH = obj

INC = includes

CC = clang

SRC_BASIC = $(addprefix $(F_B_PATH)/,$(F_BASICS))
SRC_PRINTF = $(addprefix $(F_PR_PATH)/,$(F_FT_PRINTF))

SRC=$(addprefix src/,$(SRC_BASIC)) $(addprefix src/,$(SRC_PRINTF))

OBJ_NAME = $(SRC_BASIC:.c=.o)
OBJ_NAME +=$(SRC_PRINTF:.c=.o)

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

HEAD = $(addprefix $(INC)/,$(HEADER_NAME))

CFLAGS = -Wall -Werror -Wextra

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ)
	@/usr/bin/ar rc $(NAME) $(OBJ)
	@/usr/bin/ranlib $(NAME)

$(OBJ_PATH)/%.o: src/%.c
	@echo "    Compiling $@"
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@mkdir $(OBJ_PATH)/$(F_B_PATH) 2> /dev/null || true
	@mkdir $(OBJ_PATH)/$(F_PR_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ_PATH)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

norm:
	@norminette $(SRC) | grep -v Norme -B1 || true
	@norminette $(HEAD) | grep -v Norme -B1 || true
