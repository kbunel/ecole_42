/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 15:59:56 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/28 20:30:40 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void		inc_shlvl(char **env, int i, int j)
{
	char	*tmp;
	int		lvl;

	tmp = ft_strsub(env[i], j + 1, ft_strlen(env[i] - j - 1));
	lvl = ft_atoi(tmp);
	lvl++;
	ft_memdel((void **)&tmp);
	tmp = ft_itoa(lvl);
	env[i] = ft_strjoin("SHLVL=", tmp);
	ft_memdel((void **)&tmp);
}

static void			get_shlvl(char **env)
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
			if (ft_strcmp(e_title, "SHLVL") == 0)
			{
				inc_shlvl(env, i, j);
				g++;
			}
			ft_memdel((void **)&e_title);
		}
		i++;
	}
	if (g == 0)
		ft_setenv(env, "SHLVL", "1");
}

int			main(int argc, char **argv, char **env)
{
	t_ms		ms;

	get_shlvl(env);
	ft_init_ms(&ms, argc, argv);
	ft_init_env(env, &ms);
	ft_get_line(env, &ms);
	ft_free_ms(&ms);
}
