#include "../built_in.h"

void    change_directory(char *path)
{
    char *oldpwd;
    oldpwd = get_pwd(); // store the old one
    if(chdir(path) < 0)   // change the wd
    {
        //if(special case '-' '~' ' ')
        if(ft_strcmp(path, "-") == 0)
        {
            
            printf("return=%d\n", ft_strcmp(path, "-"));
            cd_back(oldpwd);
        }
        else if(!path)    
            cd_home(oldpwd);
        else
            perror("");
    }
    else
    {
        change_pwd_var();
        change_oldpwd_var(oldpwd);
    }
}

int main(int argc, char **argv, char **env)
{
    creat_environment(env);
    change_directory(argv[1]);
    int i = 0;
    while(env[i])
    {
        if(ft_strnstr(env[i]," OLDPWD") >= 0 || ft_strnstr(env[i], "PWD") >= 0)
            printf("%s\n", env[i]);
        i++;
    }
}