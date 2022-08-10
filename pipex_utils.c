/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalakhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 20:55:41 by ikalakhi          #+#    #+#             */
/*   Updated: 2022/07/05 20:56:16 by ikalakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void    parents_wait(int id1, int id2, int *p_id)
{
    waitpid(id1, 0, NULL);
	waitpid(id2, 0, NULL);
}

void    execute_cmd(char **av, char **en)
{
    
}

char    *ft_strjoin(char *s1, char *s2)
{
        char    *c;
        size_t  i;
        size_t  p;

        if (!s1 || !s2)
                return (NULL);
        c = malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
        if (!c)
                return (NULL);
        i = 0;
        while (s1[i] != '\0' && i <= ft_strlen(s1))
        {
                c[i] = s1[i];
                i++ ;
        }
        p = 0;
        while (s2[p] != '\0' && p <= ft_strlen(s2))
        {
                c[i] = s2[p];
                i++;
                p++;
        }
        c[i] = '\0';
        return (c);
}