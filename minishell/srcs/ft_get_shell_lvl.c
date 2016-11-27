/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_shell_lvl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 22:10:08 by kbunel            #+#    #+#             */
/*   Updated: 2016/11/27 23:21:40 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int			inc_shlvl(char **env, int i, int j)
{
	char	*tmp;
	int		lvl;

	tmp = ft_strsub(env[i], j + 1, ft_strlen(env[i]) - j - 1);
	lvl = ft_atoi(tmp);
	lvl++;
	ft_memdel((void **)&tmp);
	tmp = ft_itoa(lvl);
	ft_memdel((void **)&env[i]);
	env[i] = ft_strjoin("SHLVL=", tmp);
	ft_memdel((void **)&tmp);
	return (1);
}

static int			get_shlvl_from_env(char **env, int i, int j, int g)
{
	char	*e_title;

	e_title = ft_strsub(env[i], 0, j);
	if (ft_strcmp(e_title, "SHLVL") == 0)
		g = inc_shlvl(env, i, j);
	ft_memdel((void **)&e_title);
	return (g);
}

void				ft_get_shlvl(char **env)
{
	int		i;
	int		j;
	int		g;

	i = 0;
	g = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] != '\0' && env[i][j] != '=')
			j++;
		if (env[i][j] != '\0')
			g = get_shlvl_from_env(env, i, j, g);
		i++;
	}
	if (g == 0)
		ft_setenv(env, "SHLVL", "1");
}
