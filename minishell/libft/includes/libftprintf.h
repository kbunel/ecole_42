/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:05:25 by kbunel            #+#    #+#             */
/*   Updated: 2016/05/18 17:36:38 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft.h"

# ifdef disp_error

enum		e_const
{
	DISP_ERROR = 1
}			t_const;

# else

enum		e_const
{
	DISP_ERROR = 0
}			t_const;

# endif

typedef	struct		s_arg
{
	char			*value;
	int				size;
	struct s_arg	*next;
}					t_arg;

typedef	struct		s_printf
{
	char			letter;
	char			*flag;
	char			*mfw;
	char			*precision;
	int				has_precision;
	char			*length;
	int				wc_arg;
	int				size_param;
	int				r_v_minus;
	int				return_value;
	int				display_errors;
	char			*error_letter;
	int				flag_err;
	int				prec_err;
	int				garbage;
	int				fd;
	t_arg			*arg;
	t_arg			*arg_first;
	char			nb_sign;
	int				count_errors;
}					t_printf;

int					ft_printf(char *fmt, ...);
int					ft_check_param(char *fmt, int i, t_printf *conv);
void				ft_print(void *ap, t_printf *conv);
int					is_flag(char *fmt, int i, t_printf *conv);
int					is_mfw(char *fmt, int i, t_printf *conv);
int					is_precision(char *fmt, int i, t_printf *conv);
int					is_length(char *fmt, int i, t_printf *conv);
int					is_letter(char c, t_printf *conv);
void				ft_print_s(void *ap, t_printf *conv);
void				ft_print_n(void *n, t_printf conv);
void				ft_print_dioux(void *ap, t_printf *conv);
int					ft_get_len(void *ap, t_printf conv);
char				*ft_itoa_printf(long long n, t_printf *conv);
char				*ft_itoa_printf_ull(unsigned long long n);
char				*ft_itoa_printf_octal(long long n, t_printf *conv);
char				*ft_itoa_printf_octal_j(uintmax_t n);
char				*ft_itoa_printf_hexa(long long n, t_printf *conv);
char				*ft_itoa_printf_hexa_j(uintmax_t n, t_printf *conv);
int					ft_init_d_i_len(t_printf conv, char *print);
int					ft_init_d_i_string(t_printf conv, char *print);
t_arg				*ft_new_arg(t_arg *prev_arg);
void				ft_error_msg(int error, char *str, int i, int arg_size);
int					ft_init_start(t_printf *conv);
void				ft_init_during(t_printf *conv);
char				*ft_get_length(t_printf *conv, void *ap);
char				*ft_get_length_b(t_printf *conv, void *ap);
char				*ft_get_wchar_t(wchar_t wc);
char				*ft_get_w_string(wchar_t *ap, t_printf conv);
int					ft_get_param(char *fmt, int i, t_printf *conv);
int					ft_color(char *fmt, int i, int size, t_printf *conv);

#endif
