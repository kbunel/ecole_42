/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 17:25:47 by kbunel            #+#    #+#             */
/*   Updated: 2016/11/16 21:00:47 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		get_commands(char *cmd, t_ms *ms)
{
	int		i;
	int		q;
	int		s;
	int		m;

	i = 0;
	q = 0b0;
	m = 0;
	s = 0;
	ms->cmd = (char **)malloc(sizeof(char) + 1000);
	ft_printf("{red}[%s]{eoc}\n", cmd);
	while (cmd[i] == ' ')
		i++;
	while (cmd[i] != '\0')
	{
		if (!(q & 1) && (cmd[i] == ';' || cmd[i] == ' ' || cmd[i + 1] == '\0'))
		{
			ms->cmd[m++] = ft_strsub(cmd, s, i - s + 1);
			s += i + 1;
		}
		if (cmd[i] == '\'' || cmd[i] == '"')
			q = ~q;
		if (cmd[i++] == ' ')
			s++;
	}
	ms->cmd[m] = NULL;
}

char		**ft_get_args(char	*cmd)
{
	int		i;
	int		q;
	int		s;
	int		a;
	char	**args;

	i = 0;
	q = 0b0;
	a = 0;
	s = 0;
	args = (char **)malloc(sizeof(char) + 1000);
	while (cmd[i] == ' ')
		i++;
	while (cmd[i] != '\0')
	{
		if (!(q & 1) && (cmd[i] == ' ' || cmd[i + 1] == '\0'))
		{
			args[a++] = ft_strsub(cmd, s, i - s + 1);
			s += i + 1;
		}
		else if ((q & 1) && (cmd[i] == '\'' || cmd[i] == '"'))
		{
			args[a++] = ft_strsub(cmd, s, i - s + 1);
			s += i + 1;
		}
		if (cmd[i] == '\'' || cmd[i] == '"')
			q = ~q;
		if (cmd[i] == ' ')
			s++;
		i++;
	}
	args[a] = NULL;
	return (args);
}
