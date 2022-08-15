/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalakhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:40:04 by ikalakhi          #+#    #+#             */
/*   Updated: 2022/07/06 13:43:16 by ikalakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

	// pipe
	// fork
	// child ---> cmd1
	// 			dup2()
	// 			close en[0];
	// 			execve(cmd1)
	// child2 ---> cmd2
	// 			dup2();
	// 			close end[1];
	// 			execve (cmd2)
	// parent wait and closing

void	f_error(int id)
{
	if (id == -1)
	{
		perror("invalid fork");
		exit (0);
	}
}

void    execute_cmd1(char **av, char **env, int end[2])
{
	int		fd;
    char    *path;
	char	*args;
    char    *cmd_path;

    args = args_path(av[2]);
	cmd_path = check_cmd(args, env);
	fd = open (av[1], O_RDONLY);
	if (fd == -1)
		perror("zsh");
	
    if (execve(cmd_path, args, env) == -1)
		perror("zsh");
}

int main(int ac, char **av, char **env)
{
	int	id1;
	int	id2;
	int	end[2];

	if (ac != 5)
		return (0);
	if (pipe(end) == -1)
		return (0);
	id1 = fork();
	f_error(id1);
	if (id1 == 0)
		execute_cmd1(av, env, end);
	id2 = fork();
	f_error(id2);
	if (id2 == 0)
		execute_cmd2(av, env);
	if (id1 != 0 && id2 != 0)
		parents_wait(id1, id2, end);
}
