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

	//pipe
	//fork
	//child ---> cmd1
	//			dup2()
	//			close en[0];
	//			execve(cmd1)
	//child2 ---> cmd2
	//			dup2();
	//			close end[0];
	//			execve (cmd2)
	//parent wait and closeing

int main(int ac, char **av)
{
	int	id;
	int	p_id[2];

	if (ac != 5)
		return (0);
	if (pipe(p_id) == -1)
		return (0);
	id = fork();
	if (id != 0)
		execute_cmd1();
	id = fork();
	if (id != 0)
		execute_cmd1();
	parents_wait(id1, id2, p_id);
}
