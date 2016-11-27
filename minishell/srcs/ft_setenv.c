/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 16:36:09 by kbunel            #+#    #+#             */
/*   Updated: 2016/11/27 21:04:14 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void		add_env(char **env, int i, char *name, char *value)
{
	char	*tmp;

	tmp = ft_strjoin(name, "=");
	if (value == NULL)
		value = ft_strdup("");
	env[i] = ft_strjoin(tmp, value);
	ft_memdel((void **)&tmp);
	env[++i] = NULL;
}

static int		set_env(char **env, int i, int j, char *value)
{
	char		*tmp;

	tmp = ft_strsub(env[i], 0, j + 1);
	if (value == NULL)
		value = ft_strdup("");
	env[i] = ft_strjoin(tmp, value);
	ft_memdel((void **)&tmp);
	return (1);
}

void			ft_setenv(char **env, char *name, char *value)
{
	int		i;
	int		j;
	int		g;
	char	*e_title;

	i = 0;
	g = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] != '\0' && env[i][j] != '=')
			j++;
		if (env[i][j] != '\0')
		{
			e_title = ft_strsub(env[i], 0, j);
			if (ft_strcmp(e_title, name) == 0)
				g = set_env(env, i, j, value);
			ft_memdel((void **)&e_title);
		}
		i++;
	}
	if (g == 0)
		add_env(env, i, name, value);
}
