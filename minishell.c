/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:31:31 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/31 17:35:57 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "execution/built_ins/built_in.h"
// #include "./execution/built_ins/built_in.h"
#include "./parsing/parsing.h"

int exit_status;


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

void handle_sig_int(int flag)
{
    flag = inside_child(2);
    if(flag == 0)
    {
        rl_replace_line("", 0);
        write(1, "\n", 1);
        rl_on_new_line();
        rl_redisplay();
        exit_status = 130;
        update_exit_status(130);
    }
    else if(flag == 1)
        write(1, "\n", 1);
}

int main(int argc, char const *argv[], char **env)
{
    char *str;
    (void)argv;
    (void)argc;
    signal(SIGINT, handle_sig_int);
    signal(SIGQUIT, SIG_IGN);
    create_environment(env);
    while(1)
    {
        str = readline("Minishell $>: ");
        if(!str)
            ft_exit(exit_status);
        if(!*str)
            continue;
        add_history(str);
        if(!parsing(str))
        {
            lstclear_exec();
            // ft_free_all();
            continue;
        }

        // t_exec *exec;
	    // exec = *v_exec();
 	    // while (exec)
	    // {
        //     printf("--------------<<<<<<<<<<<<<<<<<<<<<---------------\n");
        //     if( exec->args)
	    // 	{
        //         for(int i = 0; exec->args[i]; i++)
        //         {
        //             if(i != 0)
        //                 printf(" ");
        //             printf("%s", exec->args[i]);

        //         }
        //     }
        //     printf("\ncmd = [%s] path = [%s]\n \n", exec->cmd, exec->path);
        //     printf("    fdin = {%d}     fdout = {%d}",exec->fd_in, exec->fd_out);
	    // 	printf("\n------------>>>>>>>>>>>>>>>>>>>>>>--------------------\n");
        //     // close(exec->fd_in);
        //     // close(exec->fd_out);
	    // 	exec = exec->next;
	    // }
        // printf("\n=========================================================================\n");
        main_execution();
        lstclear_exec();
    }
}
