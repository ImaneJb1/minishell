#include "../built_in.h"

void    change_oldpwd_var(char *oldpwd, char **env)
{
    int i;

    i = 0;
    oldpwd = ft_strjoin("OLDPWD= ", oldpwd);
    while (env[i])
    {
        if(ft_strnstr(env[i], "OLDPWD") >= 0)
        {
            env[i] = ft_strdup(oldpwd);
            break;
        }
        i++;
    }
    
}