/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 12:05:22 by kbunel            #+#    #+#             */
/*   Updated: 2016/09/26 22:38:15 by kbunel           ###   ########.fr       */
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
	u_file = ft_strjoin(home, path);
	ft_memdel((void **)&home);
	ft_memdel((void **)&path);
	return (u_file);
}

static void		set_path(char **env, char *u_file)
{
	char	*path;

	path = NULL;
	path = getcwd(path, 0);
	ft_setenv(env, "OLDPWD", path);
	ft_memdel((void **)&path);
	chdir(u_file);
	path = getcwd(path, 0);
	ft_setenv(env, "PWD", path);
	ft_memdel((void **)&path);
}

int				b_cd(char **env, char *file)
{
	char	*u_file;

	if (file == NULL)
		u_file = NULL;
	else if (file[0] == '~')
		u_file = insert_home(env, file);
	else if (ft_strcmp(file, "-") == 0)
		u_file = ft_getenv(env, "OLDPWD");
	else
		u_file = ft_strdup(file);
	if (u_file == NULL)
		b_cd(env, "/");
	else if (access(u_file, X_OK) == 0)
		set_path(env, u_file);
	else
		ft_printf("cd: permission denied: %s\n", u_file);
	ft_memdel((void **)&u_file);
	return (1);
}
