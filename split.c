/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalakhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 08:06:02 by ikalakhi          #+#    #+#             */
/*   Updated: 2022/08/11 08:06:11 by ikalakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int count_words(char const *s1, char c)
{
    int i;
    int n;

    i = 0;
    while (s1[i] && s1[i] == c)
            i++;
    if (s1[i] == 0)
            return (0);
    n = 1;
    while (s1[i])
    {
        if (s1[i] == c)
        {
            while (s1[i] && s1[i] == c)
                i++;
            if (s1[i] != 0)
                n++;
        }
        else
            i++;
    }
        return (n);
}

char    **free_tab(char **b, int i)
{
    while (i >= 0)
    {
        if (b[i])
            free(b[i]);
        i--;
    }
    free(b);
    return (NULL);
}

char    **ft_loc(char const *s, char **big, char c)
{
    int i;
    int k;
    int y;
    
    i = 0;
    y = 0;
    while (i < count_words(s, c))
    {
        while (s[y] == c)
            y++;
        k = y;
        while (s[k] != c && s[k] != '\0')
            k++;
        big[i] = ft_substr(s, y, k - y);
        if (!big[i])
            return (free_tab(big, k));
        i++;
        y = k;
    }
    big[i] = '\0';
    return (big);
}

char    **ft_split(char *s, char c)
{
    char    **big;
    int     i;

    i = 0;
    if (!s)
        return (NULL);
    big = malloc((count_words(s, c) + 1) * sizeof(char *));
    if (big == NULL)
        return (NULL);
    big = ft_loc(s, big, c);
    return (big);
}
