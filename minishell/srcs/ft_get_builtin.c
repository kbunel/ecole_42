/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 16:10:40 by kbunel            #+#    #+#             */
/*   Updated: 2016/11/16 21:22:17 by kbunel           ###   ########.fr       */
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

static int			b_get_env(char **env, char **args)
{
	int		i;

	i = 0;
	while (env != NULL && env[i])
	{
		if (ft_strcmp(args[0], "setenv") == 0)
			ft_putstr("setenv ");
		if (!(ft_strcmp(args[0], "setenv") != 0 && !is_valid_env(env[i])))
			ft_printf("%s\n", env[i]);
		i++;
	}
	return (1);
}

int					ft_get_builtin(char **args, char **env)
{
	int		i;

	i = 0;
	if (ft_strcmp(args[0], "echo") == 0)
		return (b_echo(args));
	else if (ft_strcmp(args[0], "env") == 0
			|| (ft_strcmp(args[0], "setenv") == 0 &&
				args[1] != NULL && ft_strcmp(args[1], "-p") == 0))
		return (b_get_env(env, args));
	else if (env != NULL && ft_strcmp(args[0], "setenv") == 0)
		return (b_setenv(env, args, SETENV));
	else if (env != NULL && ft_strcmp(args[0], "unsetenv") == 0)
		return (b_setenv(env, args, UNSETENV));
	else if (ft_strcmp(args[0], "cd") == 0)
		return (b_cd(env, args[1]));
	else
		return (0);
}
