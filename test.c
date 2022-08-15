#include "pipex.h"

char    *look_for_path(char **env)
{
    int     i;
    char    *path;

    i = 0;
    while (env[i])
    {
        if (ft_strncmp(env[i], "PATH=", 5) == 0)
            path = env[i];
        i++;
    }
    return(path);
}

int main(int ac, char **ar, char **env)
{
    //int i = 0;
    char **cmd_path = ft_split(ar[2], ' ');
    // while(cmd_path[0])
    // {
        //print lsf("%s\n", cmd_path[i]);
        printf("join %s\n", ft_strjoin("/", cmd_path[0]));
        //i++;
   // }
	perror("zsh");
}
