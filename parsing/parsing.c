/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 02:09:47 by imeslaki          #+#    #+#             */
/*   Updated: 2025/04/24 13:56:40 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "../tester/tester.h"

void    parsing(char *str, char **env)
{
    t_cmd *ptr;
    t_env *x;
    creat_the_list(str);
    identify_all_types();
    if(is_valid_syntax() == FALSE)
        return;
    environment_variable_value(env);
    ptr = *v_cmd();
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
        printf("  (%d) ", ptr->index);
		ptr = ptr->next;
        printf("\n");
	}
}

int main(int argc, char const *argv[], char **env)
{
    char *str;
    int i;
    i = 0;
    // i = 1;
    if(i == 1)
    {
        i = tester();
        return i;
    }
    while(1)
    {
        lstclear_cmd();
        str = readline("Minishell $>: ");
        if(!str)
            continue;
        add_history(str);
        parsing(str, env);
    }
}
