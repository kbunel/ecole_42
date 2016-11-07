/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:00:41 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/30 12:31:25 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void		get_path(char *env, t_ms *ms)
{
	char		*path;
	int			i;

	i = 0;
	path = ft_strsub(env, 5, ft_strlen(env) - 5);
	ms->path = ft_strsplit(path, ':');
	ft_memdel((void **)&path);
	while (ms->path[i])
	{
		path = ft_strjoin(ms->path[i], "/");
		ft_memdel((void **)&ms->path[i]);
		ms->path[i++] = ft_strdup(path);
		ft_memdel((void **)&path);
	}
}

static void		get_env(char *env, t_ms *ms, int j)
{
	char		*e_title;

	e_title = ft_strsub(env, 0, j);
	if (ft_strcmp(e_title, "PATH") == 0)
		get_path(env, ms);
	else if (ft_strcmp(e_title, "PWD") == 0)
		ms->pwd = ft_strsub(env, 4, ft_strlen(env) - 4);
	else if (ft_strcmp(e_title, "OLDPWD") == 0)
		ms->oldpwd = ft_strsub(env, 7, ft_strlen(env) - 7);
	ft_memdel((void **)&e_title);
}

static void		check_env(t_ms *ms, char **env)
{
	char		*path;

	path = NULL;
	if (ms->pwd == NULL)
	{
		path = getcwd(path, 0);
		ms->pwd = ft_strdup(path);
		ft_setenv(env, "PWD", path);
		ft_memdel((void **)&path);
	}
}

void			ft_init_env(char **env, t_ms *ms)
{
	int		i;
	int		j;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] != '\0' && env[i][j] != '=')
			j++;
		if (env[i][j] != '\0')
			get_env(env[i], ms, j);
		i++;
	}
	check_env(ms, env);
}
