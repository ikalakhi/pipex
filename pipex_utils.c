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

char    *args_path(char *av)
{
    char    **args;
    char    cmd;

    args = ft_split(av, ' ');
    cmd = ft_strjoin("/", args[0]);
    return (cmd);
}

char    *look_for_path(char **env)
{
    int     i;
    char    *path;

    i = 0;
    while (env[i])
    {
        if (ft_strncmp(env[i], "PATH=", 5) == 0)
            path = env[i];
        i++ ;
    }
    return(path);
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
	perror(args);
	exit(1);
}