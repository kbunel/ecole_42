# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbunel <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/09 18:43:21 by kbunel            #+#    #+#              #
#    Updated: 2016/03/13 18:35:21 by kbunel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FONCTIONS = ft_error_msg.c ft_itoa_printf_octal.c ft_itoa_printf_octal_j.c \
			ft_printf.c ft_get_w_string.c \
			ft_length.c	ft_get_wchar_t.c \
			ft_init.c ft_new_arg.c ft_init_d_i_len.c ft_print.c \
			ft_check_valid_param.c ft_itoa_printf.c ft_print_d_i.c ft_csfs.c \
			ft_itoa_printf_hexa.c ft_itoa_printf_ull.c ft_print_s.c \
			ft_itoa_printf_hexa_j.c ft_get_error_param.c ft_add_color.c \
			ft_print_n.c ft_get_length_b.c

FONCTIONS_LIB = libft/ft_isalnum.c libft/ft_isprint.c libft/ft_lstdelone.c \
				libft/ft_memalloc.c libft/ft_memcpy.c libft/ft_putchar.c \
				libft/ft_putnbr.c libft/ft_strcat.c libft/ft_strcpy.c \
				libft/ft_strichr.c libft/ft_strlcat.c libft/ft_strncat.c \
				libft/ft_strnew.c libft/ft_strstr.c libft/ft_toupper.c \
				libft/ft_atoi.c libft/ft_isalpha.c libft/ft_itoa.c \
				libft/ft_lstiter.c libft/ft_memccpy.c libft/ft_memdel.c \
				libft/ft_putchar_fd.c libft/ft_putnbr_fd.c libft/ft_strchr.c \
				libft/ft_strdel.c libft/ft_striter.c libft/ft_strlen.c \
				libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strsub.c \
				libft/ft_wordlen.c libft/ft_bzero.c libft/ft_isascii.c \
				libft/ft_lstadd.c libft/ft_lstmap.c libft/ft_memchr.c \
				libft/ft_memmove.c libft/ft_putendl.c libft/ft_putstr.c \
				libft/ft_strclr.c libft/ft_strdup.c libft/ft_striteri.c \
				libft/ft_strmap.c libft/ft_strncpy.c libft/ft_strrchr.c \
				libft/ft_strtrim.c libft/ft_count.c	libft/ft_isdigit.c \
				libft/ft_lstdel.c libft/ft_lstnew.c libft/ft_memcmp.c \
				libft/ft_memset.c libft/ft_putendl_fd.c libft/ft_putstr_fd.c \
				libft/ft_strcmp.c libft/ft_strequ.c libft/ft_strjoin.c \
				libft/ft_strmapi.c libft/ft_strnequ.c libft/ft_strsplit.c \
				libft/ft_tolower.c libft/ft_strisub.c libft/ft_strjoin_free.c

OBJ_O_LIB = ft_isalnum.o ft_isprint.o ft_lstdelone.o \
				ft_memalloc.o ft_memcpy.o ft_putchar.o \
				ft_putnbr.o ft_strcat.o ft_strcpy.o \
				ft_strichr.o ft_strlcat.o ft_strncat.o \
				ft_strnew.o ft_strstr.o ft_toupper.o \
				ft_atoi.o ft_isalpha.o ft_itoa.o \
				ft_lstiter.o ft_memccpy.o ft_memdel.o \
				ft_putchar_fd.o ft_putnbr_fd.o ft_strchr.o \
				ft_strdel.o ft_striter.o ft_strlen.o \
				ft_strncmp.o ft_strnstr.o ft_strsub.o \
				ft_wordlen.o ft_bzero.o ft_isascii.o \
				ft_lstadd.o ft_lstmap.o ft_memchr.o \
				ft_memmove.o ft_putendl.o ft_putstr.o \
				ft_strclr.o ft_strdup.o ft_striteri.o \
				ft_strmap.o ft_strncpy.o ft_strrchr.o \
				ft_strtrim.o ft_count.o	ft_isdigit.o \
				ft_lstdel.o ft_lstnew.o ft_memcmp.o \
				ft_memset.o ft_putendl_fd.o ft_putstr_fd.o \
				ft_strcmp.o ft_strequ.o ft_strjoin.o \
				ft_strmapi.o ft_strnequ.o ft_strsplit.o \
				ft_tolower.o ft_strisub.o ft_strjoin_free.o


HEADER = libftprintf.h

HEADER_LIB = libft/libft.h

OBJ = $(FONCTIONS:.c=.o)

FLAG = -Wall -Werror -Wextra

DISP_ERROR = -Ddisp_error

all: $(NAME)

$(NAME):
	/usr/bin/gcc $(FLAG) -c $(FONCTIONS) $(FONCTIONS_LIB) -I $(HEADER) $(HEADER_LIB)
	/usr/bin/ar rc $(NAME) $(OBJ) $(OBJ_O_LIB)
	/usr/bin/ranlib $(NAME)

disp_error:
	/usr/bin/gcc $(DISP_ERROR) $(FLAG) -c $(FONCTIONS) $(FONCTIONS_LIB) -I $(HEADER) $(HEADER_LIB)
	/usr/bin/ar rc $(NAME) $(OBJ) $(OBJ_O_LIB)
	/usr/bin/ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ) $(OBJ_O_LIB)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean
	make
