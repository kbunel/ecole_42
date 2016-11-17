/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 12:05:22 by kbunel            #+#    #+#             */
/*   Updated: 2016/11/17 22:34:53 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char		*insert_home(char **env, char *file)
{
	char	*u_file;
	char	*home;
	char	*path;

	home = ft_getenv(env, "HOME");
	path = ft_strsub(file, 1, ft_strlen(file) - 1);
	if (home != NULL && path != NULL)
		u_file = ft_strjoin(home, path);
	else
		u_file = NULL;
	ft_memdel((void **)&home);
	ft_memdel((void **)&path);
	return (u_file);
}

static void		set_path(char **env, char *u_file)
{
	char	*path;

	path = NULL;
	ft_setenv(env, "OLDPWD", ft_getenv(env, "PWD"));
	ft_memdel((void **)&path);
	chdir(u_file);
	free(path);
	path = getcwd(path, 0);
	ft_setenv(env, "PWD", path);
	ft_memdel((void **)&path);
}

static void		send_file(int error, char *u_file, char **env)
{
	if (error == NO_OLDPWD)
		ft_printf("cd: NO OLDPWD SET\n");
	else if (error == NO_HOME)
		ft_printf("cd: NO HOME SET\n");
	else if (u_file == NULL)
		b_cd(env, "/");
	else if (access(u_file, X_OK) == 0)
		set_path(env, u_file);
	else
		ft_printf("cd: permission denied: %s\n", u_file);
}

int				b_cd(char **env, char *file)
{
	char	*u_file;
	int		error;

	error = -1;
	if (file == NULL)
		u_file = NULL;
	else if (file[0] == '~')
	{
		u_file = insert_home(env, file);
		error = (u_file == NULL) ? NO_HOME : -1;
	}
	else if (ft_strcmp(file, "-") == 0)
	{
		u_file = ft_getenv(env, "OLDPWD");
		error = (u_file == NULL) ? NO_OLDPWD : -1;
	}
	else
		u_file = ft_strdup(file);
	send_file(error, u_file, env);
	ft_memdel((void **)&u_file);
	return (1);
}
