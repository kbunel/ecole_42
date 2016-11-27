/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 16:48:14 by kbunel            #+#    #+#             */
/*   Updated: 2016/11/27 23:15:07 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/includes/libft.h"
# include <termios.h>
# include <term.h>
# include <signal.h>

enum
{
	CMDNOTFOUND,
	SETENV,
	UNSETENV,
	NO_OLDPWD,
	NO_HOME
};

typedef struct			s_ms
{
	char				**path;
	char				*pwd;
	char				*oldpwd;
	char				**cmd;
	char				*prompt;
}						t_ms;

typedef struct			s_quote
{
	char				*str;
	struct s_quote		*next;
}						t_quote;

void					ft_get_cmd(char **args, char **env, t_ms *ms);
int						ft_get_builtin(char **args, char **env);
void					ft_init_env(char **env, t_ms *ms);
void					ft_init_ms(t_ms *ms);
void					ft_free_ms(t_ms *ms);
void					ft_error_ms(int error, char *txt);
void					ft_get_line(char **env, t_ms *ms);
void					ft_init_term(void);
void					ft_reinit_term(void);
void					ft_setenv(char **env, char *name, char *value);
int						b_setenv(char **env, char **args, int set_type);
int						b_echo(char **args);
char					*get_cmds(char *line);
void					get_commands(char *cmd, t_ms *ms);
int						b_cd(char **env, char *file);
void					ft_get_shlvl(char **env);
char					**ft_get_env(char **env);
void					ft_free_env(char **env);

#endif
