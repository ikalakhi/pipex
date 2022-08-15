/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalakhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:52:33 by ikalakhi          #+#    #+#             */
/*   Updated: 2022/08/12 16:52:36 by ikalakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *sub;
    int             i;
    int             size;
    
    if (!s)
        return (NULL);
    if (start >= ft_strlen(s))
        return (ft_strdup(""));
    if (ft_strlen(s) < len)
        size = ft_strlen(s) - start + 1;
    else
        size = len + 1;
    sub = malloc (size * sizeof(char));
    if (!sub)
        return (NULL);
    i = 0;
    while (i < size - 1)
    {
        sub[i] = s[start];
        start++;
        i++;
    }
    sub[i] = 0;
    return (sub);
}

char    *ft_strdup(const char *s1)
{
        int             i;
        char    *p;

        i = 0;
        if (s1 == NULL)
                return (NULL);
        p = malloc(sizeof(char) * (ft_strlen(s1) + 1));
        if (p == NULL)
                return (NULL);
        while (s1[i])
        {
                p[i] = s1[i];
                i++ ;
        }
        p[i] = '\0';
        return (p);
}