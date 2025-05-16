#include "../built_in.h"

void    change_directory(char *path, char **env)
{
    char *oldpwd;
    oldpwd = get_pwd(); // store the old one
    if(chdir(path) < 0)   // change the wd
    {
        //if(special case '-' '~' ' ')
        cd_home(path);
        perror("chdir error\n");
    }
    else
    {
        change_pwd_var(env);
        change_oldpwd_var(oldpwd, env);
    }
}

// int main(int argc, char **argv, char **env)
// {
//     change_directory(argv[1], env);
//     int i = 0;
//     while(env[i])
//     {
//         if(ft_strnstr(env[i]," OLDPWD") >= 0 || ft_strnstr(env[i], "PWD") >= 0)
//             printf("%s\n", env[i]);
//         i++;
//     }
// }