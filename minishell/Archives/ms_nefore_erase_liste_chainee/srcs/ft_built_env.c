/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_setenv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 13:46:34 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/29 13:53:03 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int			is_valid_env(char *env_l)
{
	int		i;

	i = 0;
	while (env_l[i] != '\0' && env_l[i] != '=')
		i++;
	if (env_l[i] != '\0')
	{
		if (ft_strcmp(&env_l[i + 1], "''") != 0)
			return (1);
		else
			return (0);
	}
	else
		return (0);

}

int			b_get_env(char **env, char **args)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strcmp(args[0], "setenv") == 0)
			ft_putstr("setenv ");
		if (!(ft_strcmp(args[0], "setenv") != 0 && !is_valid_env(env[i])))
			ft_printf("%s\n", env[i]);
		i++;
	}
	return (1);
}

int			b_setenv(char **env, char **args)
{
	int		i;
	int		j;
	char	*name;
	char	*value;

	i = 1;
	while (args[i])
	{
		j = 0;
		while (args[i][j] != '=' && args[i][j] != '\0')
			j++;
		if (args[i][j] != '\0')
		{
			name = ft_strsub(args[i], 0, j);
			value = ft_strsub(args[i], j + 1, ft_strlen(args[i]) - j - 1);
		}
		else
		{
			name = ft_strdup(args[i]);
			value = ft_strdup("''");
		}
		ft_setenv(env, name, value);
		ft_memdel((void **)&name);
		ft_memdel((void **)&value);
		i++;
	}
	return (1);
}
