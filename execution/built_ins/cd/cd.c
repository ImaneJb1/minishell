/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 22:52:14 by ijoubair          #+#    #+#             */
/*   Updated: 2025/06/23 17:55:27 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built_in.h"

void	change_directory(char *path)
{
    char *oldpwd;
    oldpwd = get_pwd();
    printf("path = %s\n", path); // store the old one
    if(path == NULL || chdir(path) < 0)   // change the wd
    {
        if(ft_strcmp(path, "-") == 0)
            cd_back(oldpwd);
        else if(!path || ft_strcmp(path, "~") == 0)
        {
            cd_home(oldpwd);
            printf("home\n");
            return;
        }   
        else
        {
            update_exit_status(1);
            perror(path);
        }
    }
    else
    {
        printf("chkadir tma1\n");
        change_pwd_var();
        change_oldpwd_var(oldpwd);
    }
}

void	cd(t_exec *node)
{
    int num_args;

    num_args = strlen_2d_array(node->args);
    num_args -= 1;
    if(num_args > 1)
    {
        perror("cd : too many argument"); 
        return;
    }
    change_directory(node->args[1]);
}
