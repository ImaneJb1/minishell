/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 22:52:14 by ijoubair          #+#    #+#             */
/*   Updated: 2025/06/01 19:07:47 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built_in.h"

void    change_directory(char *path)
{
    char *oldpwd;
    oldpwd = get_pwd(); // store the old one
    if(chdir(path) < 0)   // change the wd
    {
        printf("failed\n");
        if(ft_strcmp(path, "-") == 0)
        {
            cd_back(oldpwd);
        }
        else if(!path || ft_strcmp(path, "~") == 0)
        {
            cd_home(oldpwd);
        }   
        else
            perror(path);
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
    num_args = strlen_2d_array(node->args);
    num_args -= 1;
    if(num_args > 1)
    {
        perror("cd : too many argument"); 
        return;
    }
    change_directory(node->args[1]);
}

// int main(int argc, char **argv, char **env)
// {
//     create_environment(env);
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