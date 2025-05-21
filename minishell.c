/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:31:31 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/21 09:53:46 by ijoubair         ###   ########.fr       */
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
    export_built_in(exec->cmd, exec->args);
    env_built_in(exec->cmd, exec->args);
    unset(exec->cmd, exec->args);
    return 1;
}

int main(int argc, char const *argv[], char **env)
{
    char *str;

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
	    	printf("(%s)  [", exec->cmd);
	    	for(int i = 0; exec->args[i]; i++)
            {
                if(i != 0)
                    printf(" ");
                printf("%s", exec->args[i]);
                
            }
	    	printf("]\n{fdin = (%d) fdout = (%d)}", exec->fd_in, exec->fd_out);
	    	printf("\n------------>>>>>>>>>>>>>>>>>>>>>>--------------------\n");
	    	exec = exec->next;
	    }
        lstclear_exec();
    }
}
