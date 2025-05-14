/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:31:31 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/14 11:35:14 by imeslaki         ###   ########.fr       */
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
        if (ptr->type & APPEND_REDIRECTION)
            printf("APPEND_REDIRECTION ");
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

int is_built_in(void)
{
    t_exec *exec;
    exec = *v_exec();
    if(!v_exec() || !(*v_exec()))
        return 0;
    export_built_in(exec->cmd, exec->args);
    env_built_in(exec->cmd, exec->args);
    unset(exec->cmd, exec->args);
    return 0;
}

int main(int argc, char const *argv[], char **env)
{
    char *str;
    // int i;
    // i = 0;
    (void)argc;
    (void)argv;
    // i = 1;
    // if(i == 1)
    // {
    //     // i = tester();
    //     return i;
    // }
    creat_environment(env);
    while(1)
    {
        lstclear_cmd();
        str = readline("Minishell $>: ");
        if(!str)
            continue;
        add_history(str);
        if(!parsing(str))
        {
            lstclear_exec();
            continue;
        }
            // print_parsing();
        if(!is_built_in())
        {
            lstclear_exec();
            continue;
        }   
    }
}
