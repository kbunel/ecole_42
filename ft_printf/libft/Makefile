# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbunel <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/30 15:24:53 by kbunel            #+#    #+#              #
#    Updated: 2016/03/12 15:37:40 by kbunel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FONCTIONS = ft_isalnum.c ft_isprint.c ft_lstdelone.c ft_memalloc.c ft_memcpy.c \
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
			ft_tolower.c ft_strisub.c ft_strjoin_free.c

HEADER = libft.h

FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	/usr/bin/gcc $(FLAG) -c $(FONCTIONS) -I $(HEADER)
	/usr/bin/ar rc $(NAME) *.o
	/usr/bin/ranlib $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean
	make
