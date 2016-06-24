/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:41:38 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/24 17:39:05 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <errno.h>
# include <time.h>
# include <fcntl.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <pwd.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include "../libft/includes/libft.h"

typedef struct			s_file
{
	char				*name;
	char				*path;
	int					type;
	int					namlen;
	struct s_file		*sub;
	int					nb_sub;
	struct s_file		*parent;
	int					links;
	int					sub_len;
	int					s_o_len;
	int					s_g_len;
	int					s_l_len;
	int					s_size_len;
	int					stat;
	int					stat_time;
	char				*pw_name;
	char				*gr_name;
	char				*mtimespec;
	char				*atimespec;
	long				ntimespec;
	long				natimespec;
	long				nntimespec;
	long				nnatimespec;
	char				*hour_year;
	char				*a_hour_year;
	int					size;
	int					blocks;
	int					listxattr;
	int					c_disp;
	char				*l_path;
	int					major;
	int					minor;
	int					argu;
	struct s_file		*next;
	struct s_file		*prev;
}						t_file;

typedef struct			s_args
{
	char				*name;
	struct s_args		*next;
	struct s_args		*prev;
}						t_args;

typedef struct			s_ls
{
	t_file				*files;
	t_file				*empty_file;
	t_args				*args;
	t_args				*args_info;
	int					w_reg;
	int					nb_args;
	char				*options;
	int					opt;
}						t_ls;

t_ls					*ft_init(void);
void					ft_free(t_ls *ls);
void					ft_get_sort(t_ls *ls, t_file *parent, t_file *file);
t_file					*ft_sort_ascii(t_file *files);
t_file					*ft_sort_time(t_file *files);
t_file					*ft_sort_reverse(t_file *files);
t_file					*ft_sort_time_last_access(t_file *files);
void					ft_print_ls(t_ls *ls);
void					ft_get_stat(t_file *new_file, t_file *parent,
		char *name, t_ls *ls);
void					ft_get_arg(t_ls *ls, int argc, char **argv);
void					ft_error_ls(char *error, char *txt);
void					ft_get_files_r(t_ls *ls);
void					get_files_r(t_file *parent, char *path, t_ls *ls);
void					ft_print_file(t_file *file, t_ls *ls, size_t len);
t_file					*new_sub_file(struct dirent *dp, t_file *parent,
		char *path, t_ls *ls);
void					new_p_file(t_ls *ls, char *name);
void					free_files(t_file *files);
void					get_lens(t_file *file);
void					print_file_l(t_file *file, t_ls *ls);
void					ft_print_l_mid(t_file *file, char acl, int c_dips,
		t_ls *ls);
t_file					*init_file(struct dirent *dp, t_file *parent,
		char *path, char *name);
void					print_file(t_file *file, t_ls *ls);
void					ft_print_arg(t_file *file, t_ls *ls);
t_file					*new_empty_file(void);
void					ft_print_name(t_file *file, char *fleche, t_ls *ls);
void					print_parent_path(char *path, t_ls *ls, t_file *parent);
void					ft_pbt(t_file *file, t_ls *ls, int nb_files, int *i);
void					ft_put_file(t_file *file, t_file *parent, t_ls *ls);
void					ft_put_last_modif(t_file *file, t_file *parent,
		t_file *g_file, int i);
void					ft_put_last_access(t_file *file, t_file *parent,
		t_file *g_file, int i);
void					ft_put_last_modif_reverse(t_file *file, t_file *parent,
		t_file *g_file, int i);
void					ft_put_last_access_reverse(t_file *file, t_file *parent,
		t_file *g_file, int i);
void					ft_free_from_args(t_file *files, t_ls *ls);

#endif
