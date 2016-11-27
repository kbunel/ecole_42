/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 22:08:34 by kbunel            #+#    #+#             */
/*   Updated: 2016/11/27 23:31:23 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			get_nb_elem(char **env)
{
	int		i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

char		**ft_get_env(char **env)
{
	int		i;
	char	**new_env;
	int		elements;

	i = 0;
	elements = get_nb_elem(env);
	new_env = (char **)malloc(sizeof(*env) * (elements + 1));
	while (env[i])
	{
		new_env[i] = ft_strdup(env[i]);
		i++;
	}
	new_env[i] = NULL;
	return (new_env);
}
