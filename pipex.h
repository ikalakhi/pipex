/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalakhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 10:34:01 by ikalakhi          #+#    #+#             */
/*   Updated: 2022/07/03 11:45:35 by ikalakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <stdio.h>

void    parents_wait(int id1, int id2, int *p_id);
void    execute_cmd(char **av, char **env);
char    *ft_strjoin(char *s1, char *s2);
char    **ft_split(char *s, char c);
size_t  ft_strlen(const char *s);

#endif
