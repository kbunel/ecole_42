/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 13:38:44 by kbunel            #+#    #+#             */
/*   Updated: 2016/03/31 19:25:58 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "../libft/includes/libft.h"

enum			e_room
{
	start,
	room,
	end,
	way
};

typedef struct		s_ant
{
	int				name;
	int				status;
	struct s_room	*room;
	struct s_ant	*next;
}					t_ant;

typedef struct		s_way
{
	struct s_room	*lr;
	struct s_room	*rr;
	int				valid;
	struct s_way	*next;
}					t_way;

typedef struct		s_room
{
	int				x;
	int				y;
	int				ants;
	char			*name;
	t_way			*way;
	int				nb_way;
	int				dist;
	struct s_room	*next;
}					t_room;

typedef struct		s_lm
{
	int				ants;
	int				start;
	int				end;
	int				infos;
	char			*map;
	t_ant			*ant;
	t_room			*r_start;
	t_room			*r_end;
	t_room			*room;
	t_room			*g_room;
	t_way			*g_way;
	t_ant			*g_ant;
}					t_lm;

void				ft_get_infos(t_lm *lm, int i, int l);
void				ft_error(int error);
int					ft_check_room(char *line, t_lm *lm, int r);
int					ft_check_comment(char *line, t_lm *lm, int l);
void				ft_init_lemin(t_lm *lm);
int					ft_get_new_room(char *line, t_lm *lm, int kind);
int					ft_get_new_way(char *line, t_lm *lm);
void				ft_check_datas(t_lm lm);
void				ft_get_paths(t_lm *lm);
void				sh_path(t_lm lm, t_room *g_room, t_way *g_way, int i);
char				*ft_get_name(char *line, int kind, int r);
void				ft_free(t_lm *lm);
void				ft_check_new_way(t_way *new_way, t_way *new_way_2);

#endif
