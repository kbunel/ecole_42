/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 13:32:13 by kbunel            #+#    #+#             */
/*   Updated: 2015/12/18 03:48:54 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_fillit.h"

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	int		a;
	char	**str;

	i = 0;
	a = 0;
	if ((str = ft_memalloc((ft_count(s, c) + 1) * (sizeof(str)))))
	{
		while (s[i] != '\0')
		{
			while (s[i] == c)
				i++;
			if (s[i] != '\0')
			{
				str[a++] = ft_strsub(s, i, ft_wordlen(s, c, i));
				i += ft_wordlen(s, c, i);
			}
		}
		str[a] = ft_memalloc(1);
		str[a] = NULL;
		return (str);
	}
	else
		return (NULL);
}
