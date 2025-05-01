/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:31:31 by imeslaki          #+#    #+#             */
/*   Updated: 2025/04/27 22:42:15 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "./built_ins/built_in.h"
#include "./parsing/parsing.h"


void print_parsing(void)
{
    t_cmd *ptr = *v_cmd();
    while(ptr)
	{
        if(ft_strcmp(ptr->content, "env") == 0)
        {
            env_built_in();
            break;
        }
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
    print_working_directory();
    change_directory("..");
    print_working_directory();
    create_environment(env);
    while(1)
    {
        lstclear_cmd();
        str = readline("Minishell $>: ");
        if(!str)
            continue;
        add_history(str);
        parsing(str);
        print_parsing();
    }
}
