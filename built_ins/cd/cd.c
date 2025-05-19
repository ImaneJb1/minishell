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
            cd_back(oldpwd);
        }
        else if(!path || ft_strcmp(path, "~") == 0)    
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

void    cd(t_exec *node)
{
    char *command;
    int num_args;

    command = node->cmd;
    if(ft_strcmp(command, "cd") == 0)
    {
        num_args = strlen_2d_array(node->args);
        if(num_args > 1)
        {
            perror("cd : too many argument"); 
            return;
        }
        change_directory(node->args[0]);
    }
}

// int main(int argc, char **argv, char **env)
// {
//     creat_environment(env);
//     for(int i = 0; env[i]; i++)
//         printf("%s\n", env[i]);
//     change_directory(argv[1]);
//     int i = 0;
//     while(env[i])
//     {
//         if(ft_strnstr(env[i]," OLDPWD") >= 0 || ft_strnstr(env[i], "PWD") >= 0)
//             printf("%s\n", env[i]);
//         i++;
//     }
// }