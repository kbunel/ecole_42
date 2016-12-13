/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 15:59:56 by kbunel            #+#    #+#             */
/*   Updated: 2016/12/13 23:11:30 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			main(int argc, char **argv, char **env)
{
	t_ms		ms;
	char		**my_env;

	(void)argc;
	(void)argv;
	signal(SIGINT, SIG_IGN);
	my_env = ft_get_env(env);
	ft_get_shlvl(my_env);
	ft_init_ms(&ms);
	ft_init_env(my_env, &ms);
	ft_get_line(my_env, &ms);
	ft_free_ms(&ms);
	ft_free_env(my_env);
}
