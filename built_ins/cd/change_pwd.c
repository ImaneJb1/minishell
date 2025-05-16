#include "../built_in.h"

char    *get_pwd(void)
{
    char cwd[PATH_MAX];
        return(getcwd(cwd, sizeof(cwd)));
}

void    change_pwd_var(char **env)
{
    int i;
    char *pwd;

    i = 0;
    pwd = get_pwd();
    pwd = ft_strjoin("PWD= ", pwd);
    while (env[i])
    {
        if(ft_strnstr(env[i], "PWD") >= 0)
        {
            env[i] = ft_strdup(pwd);
            break;
        }
        i++;
    }
    
}