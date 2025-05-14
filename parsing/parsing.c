/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 02:09:47 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/14 11:12:28 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "../tester/tester.h"
#include "../built_ins/built_in.h"

void	creat_the_cmd_list(char *line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	str = NULL;
	if(!line)
		return;
	str = separat_with_one_space(line);
	static void (*list[])(char *str, int *i) = {
		is_arg, is_double_quote, is_singl_quote,
		is_pipe, is_redir_out_append, is_heredoc,
		is_redir_in, is_redir_out, is_var};
 	while (str[i])
	{
		j = 0;
		if (str[i] == ' ' && i++)
			add_to_cmd_list(0, 0);
		while(j < 8)
			list[j++](str, &i);
	}
	identify_all_types();
	index_the_cmd_list();
}

bool	is_valid_syntax(void)
{
	t_cmd *ptr;

	ptr = *v_cmd();
	while(ptr)
	{
		if(check_pipe_syntax(ptr) < 0 || check_unclosed_quotes(ptr) != 0 
		|| unexpected_token(ptr) < 0 ||	redir_errors(ptr) < 0 || if_special_at_end(ptr) < 0)
			return(FALSE);
		ptr = ptr->next;
	}
	return(TRUE);
}
void	expand_variable_value(void)
{
	t_cmd	*head;

	head = *v_cmd();
	while (head)
	{
		if (head->type & VARIABLE)
			change_var_value(head);
		head = head->next;
	}
	remove_quotes();
}

void fill_the_exec_struct(void)
{
	t_cmd *cmd;
	t_exec *list;
	
	cmd = *v_cmd();
	list = *v_exec();
	while (cmd)
	{
		list = check_cmd(&cmd, list);
		lstadd_exec_back(v_exec(), list);
		if(cmd)
			cmd = cmd->next;
	}
}

int    parsing(char *str)
{
    creat_the_cmd_list(str);  
    if(is_valid_syntax() == FALSE)
        return (lstclear_cmd(), 1);
    expand_variable_value();
    fill_the_exec_struct();
	t_exec *exec;
	exec = *v_exec();
 	while (exec)
	{
		printf("{(%s)  ", exec->cmd);
		printf("[");
		for(int i = 0; exec->args[i]; i++)
			printf("%s ", exec->args[i]);
		printf("]}\n");
		exec = exec->next;
	}
	lstclear_cmd();
	// lstclear_exec();
    return 1;
}
