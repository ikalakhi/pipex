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

void    parents_wait(int id1, int id2, int *end)
{
    close (end[0]);
    close (end[1]);
    waitpid(id1, 0, NULL);
	waitpid(id2, 0, NULL);
}

void    execute_cmd(char **av, char **env)
{
    ft_split(*env, ':');
    ft_strjoin();
}