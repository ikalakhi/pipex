/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalakhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:54:19 by ikalakhi          #+#    #+#             */
/*   Updated: 2022/08/16 14:59:33 by ikalakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*path;
	size_t	i;
	size_t	p;

	if (!s1 || !s2)
		return (NULL);
	path = malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!path)
		return (NULL);
	i = 0;
	while (s1[i] != '\0' && i <= ft_strlen(s1))
	{
		path[i] = s1[i];
		i++ ;
	}
	p = 0;
	while (s2[p] != '\0' && p <= ft_strlen(s2))
	{
		path[i] = s2[p];
		i++;
		p++;
	}
	path[i] = '\0';
	return (path);
}

void	free_pointer(char **pointer)
{
	int	i;

	i = 0;
	while (pointer[i])
	{
		if (pointer[i])
			free(pointer[i]);
		i++;
	}
	free(pointer);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
