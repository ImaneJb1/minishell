/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:31:31 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/19 16:15:24 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "./built_ins/built_in.h"
#include "./parsing/parsing.h"


void print_parsing(void)
{
    t_cmd *ptr = *v_cmd();
    printf("----------------------------------------------\n");
    printf("                    PARSING                   \n");
    printf("----------------------------------------------\n");
    while(ptr)
	{
        printf("[%s] = ", ptr->content);
        if (ptr->type & WORD)
        printf("WORD ");
        if (ptr->type & FILE_NAME)
            printf("FILE_NAME ");
        if (ptr->type & CMD)
            printf("CMD ");
        if (ptr->type & CMD_ARG)
            printf("CMD_ARG ");
        if (ptr->type & DOUBLE_Q)
            printf("DOUBLE_Q "); 
        if (ptr->type & SINGLE_Q)
            printf("SINGLE_Q ");
        if (ptr->type & PIPE)
            printf("PIPE ");
        if (ptr->type & HERE_DOC)
            printf("HERE_DOC ");
        if (ptr->type & REDIR_IN)
            printf("REDIR_IN ");
        if (ptr->type & REDIR_OUT)
            printf("REDIR_OUT ");
        if (ptr->type & APPEND)
            printf("APPEND ");
        if (ptr->type & PATH)
            printf("PATH ");
        if (ptr->type & VARIABLE)
            printf("VARIABLE");
        if (ptr->type & DELIMITER)
            printf("DELIMITER");
        printf("  (%d) ", ptr->index);
		ptr = ptr->next;
        printf("\n");
	}
    printf("----------------------------------------------\n");
    printf("----------------------------------------------\n");
}
// exec->in = open()
int is_built_in(void)
{
    t_exec *exec;
    t_env *our_env;
    
    our_env = *v_env();
    exec = *v_exec();
    if(!v_exec() || !(*v_exec()))
        return 0;
    // printf("input cmd : (%s)\n", (*v_cmd())->content);
    //   while(our_env)
    // {
    //     if(ft_strcmp(our_env->key,"OLDPWD") == 0 || ft_strcmp(our_env->key, "PWD") == 0)
    //     {   
    //         if(ft_strcmp(our_env->key,"OLDPWD") == 0)
    //             printf(" ------------ OLDPWD ");
    //         else if(ft_strcmp(our_env->key,"PWD") == 0)
    //             printf("---------------PWD ");
    //         printf("%s\n", our_env->value);
    //     }
    //     our_env = our_env->next;
    // }
    // printf("------------------------------------------------------------------------------\n");
    // our_env = *v_env();
    // while(our_env)
    // {
    //     if(ft_strcmp(our_env->key,"OLDPWD") == 0 || ft_strcmp(our_env->key, "PWD") == 0)
    //     {   
    //         if(ft_strcmp(our_env->key,"OLDPWD") == 0)
    //             printf("OLDPWD ");
    //         else if(ft_strcmp(our_env->key,"PWD") == 0)
    //             printf("PWD ");
    //         printf("%s\n", our_env->value);
    //     }
    //     our_env = our_env->next;
    // }
    ft_free(*v_cmd());
    *v_cmd() = NULL;  
    export_built_in(exec->cmd, exec->args);
    env_built_in(exec->cmd, exec->args);
    unset(exec->cmd, exec->args);
    return 0;
}

int main(int argc, char const *argv[], char **env)
{
    char *str;

    creat_environment(env);
    while(1)
    {
        str = readline("Minishell $>: ");
        if(!str)
            continue;
        add_history(str);
        if(!parsing(str))
        {
            ft_free(*v_exec());
            *v_exec() = NULL;
            continue;
        }
        // print_parsing();
            // print_parsing();
        if(!is_built_in())
        {
            ft_free(*v_exec());
            *v_exec() = NULL;
            continue;
        }
    }
}

// int main(int argc, char **argv, char **env)
// {
//     t_env *our_env;
    
//     creat_environment(env);
//     our_env = *v_env();
//     // for(int i = 0; env[i]; i++)
//     //     printf("%s\n", env[i]);
//     printf("----------------------------------------\n");
//     change_directory("-");
//     int i = 0;
//     while(our_env)
//     {
//         if(ft_strcmp(our_env->key,"OLDPWD") == 0 || ft_strcmp(our_env->key, "PWD") == 0)
//         {   
//             if(ft_strcmp(our_env->key,"OLDPWD") == 0)
//                 printf("OLDPWD ");
//             else if(ft_strcmp(our_env->key,"PWD") == 0)
//                 printf("PWD ");
//             printf("%s\n", our_env->value);
//         }
//         our_env = our_env->next;
//     }
// }