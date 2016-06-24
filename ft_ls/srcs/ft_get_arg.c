/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 13:03:02 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/22 18:55:25 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void			new_arg(t_ls *ls, char *arg)
{
	t_args		*new_arg;
	t_args		*g_arg;

	g_arg = ls->args;
	while (g_arg != NULL && g_arg->next != NULL)
		g_arg = g_arg->next;
	new_arg = (t_args *)malloc(sizeof(t_args));
	new_arg->name = ft_strdup(arg);
	new_arg->next = NULL;
	ls->nb_args++;
	if (g_arg != NULL)
	{
		g_arg->next = new_arg;
		new_arg->prev = g_arg;
	}
	else
	{
		ls->args = new_arg;
		new_arg->prev = NULL;
	}
}

static void			check_letter(t_ls *ls, int i)
{
	char	*tmp;
	char	*replace;
	char	o;

	replace = ft_strdup("1lx");
	if (ls->options[i] == 'g')
	{
		tmp = ft_memalloc(ft_strlen(ls->options) + 2);
		ft_strcat(tmp, ls->options);
		ft_strcat(tmp, "l");
		ft_memdel((void **)&ls->options);
		ls->options = ft_strdup(tmp);
		ft_memdel((void **)&tmp);
	}
	else if (ft_strchr(replace, ls->options[i]) != NULL)
	{
		o = ls->options[i];
		while (i >= 0)
		{
			if (ft_strchr(replace, ls->options[i]) != NULL)
				ls->options[i] = o;
			i--;
		}
	}
	ft_memdel((void **)&replace);
}

static void			check_options(t_ls *ls)
{
	int		i;
	int		j;
	char	*legal;

	i = 0;
	j = 0;
	legal = ft_strdup("1afglrtuxAGR");
	while (ls->options[i] != '\0')
	{
		while (legal[j] != '\0' && legal[j] != ls->options[i])
			j++;
		if (legal[j] == '\0' && ft_strcmp(ls->options, "-") != 0)
		{
			ft_printf("%fft_ls: illegal option -- %c\n", 2, ls->options[i]);
			ft_printf("%fusage: ft_ls [-%s] [file ...]\n", 2, legal);
			exit(EXIT_FAILURE);
		}
		check_letter(ls, i);
		i++;
		j = 0;
	}
	ft_memdel((void **)&legal);
}

static void			get_option(t_ls *ls, char *argv)
{
	char	*tmp_opt;
	char	*arg_opt;

	arg_opt = ft_strsub(argv, 1, ft_strlen(argv) - 1);
	if (ls->options != NULL)
	{
		tmp_opt = ft_strdup(ls->options);
		ft_memdel((void **)&ls->options);
		ls->options = ft_strjoin(tmp_opt, arg_opt);
		ft_memdel((void **)&tmp_opt);
	}
	else
		ls->options = ft_strdup(arg_opt);
	ft_memdel((void **)&arg_opt);
}

void				ft_get_arg(t_ls *ls, int argc, char **argv)
{
	int		arg;

	arg = 1;
	get_option(ls, "-1");
	while (arg < argc)
	{
		if (ls->opt == 0 && ft_strcmp(argv[arg], "--") == 0)
			ls->opt = 1;
		else if (ls->opt == 0 && argv[arg][0] == '-'
				&& ft_strcmp(argv[arg], "-") != 0)
			get_option(ls, argv[arg]);
		else
		{
			new_arg(ls, argv[arg]);
			ls->opt = 1;
		}
		arg++;
	}
	if (ls->args == NULL)
		new_arg(ls, ".");
	if (ls->options != NULL)
		check_options(ls);
}
