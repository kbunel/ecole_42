/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 15:16:11 by kbunel            #+#    #+#             */
/*   Updated: 2016/06/30 15:43:15 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_getenv(char **env, char *name)
{
	int		i;
	int		j;
	char	*title;

	i = 0;
	while (env[i] != NULL)
	{
		j = 0;
		while (env[i][j] != '=' && env[i][j] != '\0')
			j++;
		if (env[i][j] != '\0')
		{
			title = ft_strsub(env[i], 0, j);
			if (ft_strcmp(title, name) == 0)
			{
				ft_memdel((void **)&title);
				return (ft_strsub(env[i], j + 1, ft_strlen(env[i]) - j));
			}
			ft_memdel((void **)&title);
		}
		i++;
	}
	return (NULL);
}
