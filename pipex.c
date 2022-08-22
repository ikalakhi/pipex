/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalakhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:40:12 by ikalakhi          #+#    #+#             */
/*   Updated: 2022/08/19 18:35:02 by ikalakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

char	*join_check_cmd(char *args, char **env)
{
	char	*cmd;
	char	*cmd_path;

	cmd = ft_strjoin("/", args);
	cmd_path = check_cmd(cmd, env);
	free (cmd);
	return (cmd_path);
}

void	execute_cmd1(char **av, char **env, int end[2])
{
	int		fd;
	char	**args;
	char	*cmd_path;

	check_file(av[1], 2);
	check_file(av[1], 0);
	args = ft_split(av[2], ' ');
	if (check_executable(args[0]) == 0)
		cmd_path = args[0];
	else
		cmd_path = join_check_cmd(args[0], env);
	fd = open (av[1], O_RDONLY);
	if (fd == -1)
		error();
	close(end[0]);
	dup2(fd, 0);
	dup2(end[1], 1);
	closing_fd(end[0], fd);
	if (execve(cmd_path, ft_split(av[2], ' '), env) == -1)
		perror("zsh");
}

void	execute_cmd2(char **av, char **env, int end[2])
{
	int		fd;
	char	**args;
	char	*cmd_path;

	fd = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd == -1)
		error();
	check_file(av[4], 1);
	check_file(av[4], 2);
	args = ft_split(av[3], ' ');
	if (check_executable(args[0]) == 0)
		cmd_path = args[0];
	else
		cmd_path = join_check_cmd(args[0], env);
	close(end[1]);
	dup2(fd, 1);
	dup2(end[0], 0);
	closing_fd(end[0], fd);
	free_pointer(args);
	if (execve(cmd_path, ft_split(av[3], ' '), env) == -1)
		perror("zsh");
}

int	main(int ac, char **av, char **env)
{
	int	id1;
	int	id2;
	int	end[2];

	if (ac != 5)
		return (0);
	if (pipe(end) == -1)
		perror("zsh");
	id1 = fork();
	f_error(id1);
	if (id1 == 0)
		execute_cmd1(av, env, end);
	id2 = fork();
	f_error(id2);
	if (id2 == 0)
		execute_cmd2(av, env, end);
	close(end[0]);
	close(end[1]);
	waitpid(id1, NULL, 0);
	waitpid(id2, NULL, 0);
	return (0);
}
