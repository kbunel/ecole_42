/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 17:25:47 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/29 18:59:24 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void		get_args(t_cmd *new_cmd, char *cmd, int i)
{
	char		q;
	int			s;
	t_args		*g_args;
	t_args		*new_args;
	
	g_args = new_cmd->args;
	while (g_args != NULL && g_args->next != NULL)
		g_args = g_args->next;
	while (cmd[i] == ' ')
		i++;
	if (cmd[i] != '\0')
	{
		new_args = (t_args *)malloc(sizeof(t_args));
		while (cmd[i] != '\0')
		{
			if (cmd[i] == '\'' || cmd[i] == '"')
			{
				s = i;
				q = cmd[i]
				while (cmd[i] != q)
					i++;
				new_args->name = ft_strsub(cmd, s, i - s + 1);
				new_args->next = NULL;
			}
			else
			{
				s = i;
				while (cmd[i] != ' ')
					i++;
				new_args->name = ft_strsub(cmd, s, i - s + 1);
				new_args->next = NULL;
			}
			while (cmd[i] == ' ')
				i++;
		}
	}
}

static int		get_cmd_name(t_cmd *new_cmd, char *cmd)
{
	int		i;

	i = 0;
	while (cmd[i] == ' ')
		i++;
	while (cmd[i] != ' ' && cmd[i] != '\0')
		i++;
	new_cmd->name = ft_strsub(cmd, 0, i);
	return (i);
}

void			get_new_cmd(t_ms *ms, char *cmd)
{
	t_cmd		*g_cmd;
	t_cmd		*new_cmd;
	int			i;

	g_cmd = ms->cmd;
	while (g_cmd != NULL && g_cmd->next != NULL)
		g_cmd = g_cmd->next;
	new_cmd = (t_cmd *)malloc(sizeof(t_cmd));
	new_cmd->args = NULL;
	new_cmd->next = NULL;
	i = get_cmd_name(new_cmd, cmd);
	while (cmd[i] != '\0')
		get_args(new_cmd, cmd, i);
	if (g_cmd != NULL)
		g_cmd->next = new_cmd;
	else
		ms->cmd = new_cmd;
}

void		get_commands(char *cmd, t_ms *ms)
{
	int		i;
	int		q;
	int		s;
	int		m;
	char	*c_cmd;

	i = 0;
	q = 0b0;
	m = 0;
	s = 0;
	while (cmd[i] != '\0')
	{
		if (!(q & 1) && (cmd[i] == ';' || cmd[i + 1] == '\0'))
		{
			c_cmd = ft_strsub(cmd, s, i - s + 1);
			get_new_cmd(ms, c_cmd);
			s += i + 1;
		}
		if (cmd[i] == '\'' || cmd[i] == '"')
			q = ~q;
		i++;
	}
}
//
//char		**ft_get_args(char	*cmd)
//{
//	int		i;
//	int		q;
//	int		s;
//	int		a;
//	char	**args;
//
//	i = 0;
//	q = 0;
//	a = 0;
//	s = 0;
//	args = (char **)malloc(sizeof(char));
//	while (cmd[i] != '\0')
//	{
//		if (!(q & 1) && (cmd[i] == ' ' || cmd[i + 1] == '\0'))
//		{
//			args[a++] = ft_strsub(cmd, s, i - s);
//			s += i + 1;
//		}
//		else if ((q & 1) && (cmd[i] == '\'' || cmd[i] == '"'))
//		{
//			args[a++] = ft_strsub(cmd, s, i - s);
//			s += i + 1;
//		}
//		if (cmd[i] == '\'' || cmd[i] == '"')
//			q = ~q;
//		i++;
//	}
//	return (args);
//}
