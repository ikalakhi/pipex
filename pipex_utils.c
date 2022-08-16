/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 20:55:41 by ikalakhi          #+#    #+#             */
/*   Updated: 2022/08/16 14:48:04 by ikalakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	check_file(char *args, int i)
{
	if (i == 0)
	{
		if (access(args, R_OK) == -1)
		{
			perror("zsh : 0");
			exit(1);
		}
	}
	if (i == 1)
	{
		if (access(args, W_OK) == -1)
		{
			perror("zsh : 1");
			exit(1);
		}
	}
	if (i == 2)
	{
		if (access(args, F_OK) == -1)
		{
			perror("zsh : 2");
			exit(1);
		}
	}
}

char	*look_for_path(char **env)
{
	int		i;
	char	*path;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			path = env[i];
		i++ ;
	}
	return (path);
}

char	*check_cmd(char *args, char **env)
{
	char	*path;
	char	**env_path;
	char	*cmd;
	int		i;

	i = 0;
	path = look_for_path(env);
	env_path = ft_split(path, ':');
	while (env_path[i])
	{
		cmd = ft_strjoin(env_path[i], args);
		if (access(cmd, X_OK) == 0)
			return (cmd);
		i++;
	}
	write(2, "Error: Command not found\n", 25);
	exit(EXIT_FAILURE);
}
