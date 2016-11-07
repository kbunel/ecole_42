/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 15:59:56 by kbunel            #+#    #+#             */
/*   Updated: 2016/10/04 22:59:41 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			main(int argc, char **argv, char **env)
{
	t_ms		ms;

	(void)argc;
	(void)argv;
	get_shlvl(env);
	ft_init_ms(&ms);
	ft_init_env(env, &ms);
	ft_get_line(env, &ms);
	ft_free_ms(&ms);
}
