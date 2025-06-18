/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_the_exec_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:20:25 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/18 18:23:58 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_exec	*add_to_exec_list(char *str, t_exec *cur, int flag)
{
	static int	i;

	if (flag == 1)
	{
		cur->cmd = ft_strdup(str);
		return (cur);
	}
	else if (flag == 2)
	{
		cur->args[i] = ft_strdup(str);
		i++;
		return (cur);
	}
	else if (flag == 0)
	{
		if (cur && cur->args && cur->args[0])
			cur->args[i] = NULL;
		i = 0;
		return (cur);
	}
	return (cur);
}

void fill_node(t_cmd *tokens, t_exec **cmd)
{
	fill_fds_into_exec(tokens, cmd);
	fill_args(tokens, cmd);
	fill_cmd(tokens, cmd);
}

int 	fill_the_exec_struct(void)
{
	t_cmd *tokens;
	t_exec *cmd;
	
	if(!v_cmd() || !(*v_cmd()))
        return 0;
	tokens = *v_cmd();
	cmd = new_exec_node();
	while (tokens)
	{
		fill_node(tokens, &cmd);
		if(heredoc_exit_with_signal(2))
		{
			heredoc_exit_with_signal(0);
			return 0;
		}
		inside_child(0);
		if(tokens->type & PIPE)
		{
			is_arg_of_cmd(0);
			lstadd_exec_back(v_exec(), cmd);
			cmd = add_to_exec_list(NULL, cmd, 0);
			cmd = new_exec_node();
		}
		tokens = tokens->next;
	}
	if (cmd)
		cmd = add_to_exec_list(NULL, cmd, 0);
	lstadd_exec_back(v_exec(), cmd);
	is_arg_of_cmd(0);
	return 1;
}

