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
	if (id1 == 0)
		execute_cmd(av, env);
	id2 = fork();
	if (id2 == 0)
		execute_cmd(av, env);
	if (id1 != 0 && id2 != 0)
		parents_wait(id1, id2, end);
}
