/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 13:14:10 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/27 15:51:50 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"
# include <errno.h>

int		main(int argc, char **argv, char **e)
{
	(void)argc;
	char	*path;
	errno = 0;
	pid_t		pid;
	int			stat;

	path = NULL;
	pid = fork();
	if (pid == 0)
	{
		ft_printf("{green}PID: %d{eoc}\n", pid);
		path = getcwd(path, 0);
		ft_printf("%s {cyan}[%s]{eoc} $> \n", path, e[17]);
		chdir("libft/srcs/ft_printf");
		ft_memdel((void **)&path);
		if (execve("/bin/ls", argv, e) == -1)
			ft_printf("%f{red}%s{eoc}\n", 2, strerror(errno));
	}
	else if (pid > 0)
	{
		wait(&stat);
		ft_printf("{green}PID: %d{eoc}\n", pid);
		path = getcwd(path, 0);
		e[17] = ft_strdup(path);
		ft_printf("%s {cyan}[%s]{eoc} $> \n", path, e[17]);
		if (execve("/bin/ls", argv, e) == -1)
			ft_printf("%f{red}%s{eoc}\n", 2, strerror(errno));
		ft_memdel((void **)&path);
	}
	else
		ft_printf("Probleme");
	return (0);
}
