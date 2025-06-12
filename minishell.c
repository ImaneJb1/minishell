/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:31:31 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/12 16:26:34 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution/built_ins/built_in.h"
#include "minishell.h"
#include "./parsing/parsing.h"

int		exit_status;

void	print_parsing(void)
{
	t_cmd	*ptr;

	ptr = *v_cmd();
	printf("----------------------------------------------\n");
	printf("                    PARSING                   \n");
	printf("----------------------------------------------\n");
	while (ptr)
	{
		printf("[%s] = ", ptr->content);
		if (ptr->type & WORD)
			printf("WORD ");
		if (ptr->type & FIELD)
			printf("FIELD ");
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



void	create_env_and_handle_signals(char	**env)
{
	signal(SIGINT, handle_sig_int);
	signal(SIGQUIT, SIG_IGN);
	create_environment(env);
}

int	main(int argc, char const *argv[], char **env)
{
	char	*str;

	(void)argv;
	(void)argc;
	create_env_and_handle_signals(env);
	while (1)
	{
		str = readline("Minishell $>: ");
		if (!str)
			(free(str), clear_history(), ft_exit(exit_status));
		if (!*str)
		{
			free(str);
			continue ;
		}
		add_history(str);
		if (!parsing(str))
		{
			lstclear_exec();
			continue ;
		}
		main_execution();
		lstclear_exec();
	}
}
