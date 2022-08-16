/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:27:41 by yel-aoun          #+#    #+#             */
/*   Updated: 2022/08/16 14:45:00 by ikalakhi         ###   ########.fr       */
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

void	error(void);
void	f_error(int id);
void	ft_print(char *s);
void	check_file(char *args, int i);
void	parents_wait(int id1, int id2, int *p_id);
void	execute_cmd1(char **av, char **env, int end[2]);

char	*args_path(char **av);
char	*look_for_path(char **env);
char	*ft_strdup(const char *s1);
char	**ft_split(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*check_cmd(char *args, char **env);
char	*ft_substr(char const *s, unsigned int start, size_t len);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

size_t	ft_strlen(const char *s);

#endif
