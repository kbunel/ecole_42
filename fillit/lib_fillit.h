/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_fillit.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 14:31:32 by kbunel            #+#    #+#             */
/*   Updated: 2015/12/18 16:38:57 by tgerboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_FILLIT_H
# define LIB_FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef	struct		s_list
{
	char			p;
	int				cc[8];
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

void				ft_putchar(char c);
void				ft_putstr(char const *s);
int					ft_check(char *tetrim, int l, int nb, int i);
char				**ft_getelem(char *tetrim, int m);
t_list				*ft_lstgetelem(char **elem, int nb, t_list	*tetris);
void				*ft_memalloc(size_t size);
char				**ft_strsplit(char const *s, char c);
void				ft_bzero(void *s, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_wordlen(const char *s, char c, size_t i);
int					ft_count(char const *s, char c);
char				*ft_create_map(int len);
void				*ft_memset(void *b, int c, size_t len);
int					ft_size_min_map(int nb);
char				*ft_solve_it(t_list *tetris, char *map);
char				*ft_check_map(char *str);
void				ft_exit(int nb);

#endif
