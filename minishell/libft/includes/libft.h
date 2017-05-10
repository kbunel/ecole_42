/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:41:38 by kbunel            #+#    #+#             */
/*   Updated: 2017/05/10 19:09:05 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <dirent.h>
# include "libftprintf.h"

# define BUFF_SIZE 10

typedef	struct		s_gnl
{
	char			*buf;
	char			*tmp1;
	char			*tmp2;
	int				i;
	int				fd;
	int				in;
	int				r;
	struct s_gnl	*prev;
	struct s_gnl	*next;
}					t_gnl;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *str);
long long			ft_atoi_ll(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
char				*ft_itoa_ll(long long n);
void				*ft_memalloc(size_t size);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_puthexa(unsigned int n, char x);
void				ft_putnbr(int n);
void				ft_putunbr(unsigned int n);
void				ft_putoctal(unsigned int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr_ll(long long n);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
char				*ft_strcat(char *dest, const char *src);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_free(char const *s1, char const *s2);
int					ft_strcmp (const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strnew(size_t size);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strncmp (const char *s1, const char *s2, size_t n);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strtrim(char const *s);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(char const *s, char c);
int					ft_strichr(char *str, int i, char c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strisub(char *dest, char *src, int i);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_toupper (int c);
int					ft_tolower (int c);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_wordlen(const char *s, char c, size_t i);
int					ft_count(char const *s, char c);
int					ft_intlen(int n);
void				ft_check(int nb);
int					get_next_line(int const fd, char **line);
void				ft_error(char *txt, int ligne);
int					ft_free_ret(void **ap);
void				ft_dir(char *dir_name);
int					ft_strleni(int nb);
char				*ft_getenv(char **env, char *name);
int					ft_strcchr(const char *str, char c);
void				ft_replacechar(char *str, char search, char replace);
int					ft_strcfirst(char *str, char c);

#endif
