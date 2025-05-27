/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:31:31 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/27 11:53:55 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "execution/built_ins/built_in.h"
#include "./execution/built_ins/built_in.h"
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
int is_built_in(void)
{
    t_exec *exec;
    t_env *our_env;
    
    our_env = *v_env();
    exec = *v_exec();
    if(!v_exec() || !(*v_exec()))
        return 0;
    ft_free(*v_cmd());
    *v_cmd() = NULL;  
    export(exec);
    env(exec);
    unset(exec);
    return 1;
}

int main(int argc, char const *argv[], char **env)
{
    char *str;
    (void)argv;
    (void)argc;
    creat_environment(env);
    while(1)
    {
        str = readline("Minishell $>: ");
        if(!str || !*str)
            continue;
        add_history(str);
        if(!parsing(str))
        {
            ft_free(*v_exec());
            *v_exec() = NULL;
            continue;
        }
        if(!is_built_in())
        {
            ft_free(*v_exec());
            *v_exec() = NULL;
            continue;
        }
        
        t_exec *exec;
	    exec = *v_exec();
 	    while (exec)
	    {
            printf("--------------<<<<<<<<<<<<<<<<<<<<<---------------\n");
            if( exec->args)
	    	{
                for(int i = 0; exec->args[i]; i++)
                {
                    if(i != 0)
                        printf(" ");
                    printf("%s", exec->args[i]);

                }
            }
            printf("\ncmd = [%s] path = [%s]\n index = %i\n", exec->cmd, exec->path, exec->index);
	    	printf("\n------------>>>>>>>>>>>>>>>>>>>>>>--------------------\n");
            // close(exec->fd_in);
            // close(exec->fd_out);
	    	exec = exec->next;
	    }
        printf("\n=========================================================================\n");
        main_execution();
        lstclear_exec();
    }
}
