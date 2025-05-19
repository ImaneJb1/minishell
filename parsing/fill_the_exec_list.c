/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_the_exec_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:20:25 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/19 18:39:31 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_exec	*add_to_exec_list(char *str, t_exec *cur, int flag)
{
	t_exec *node;
	static int i;

	if(flag == 1)
	{
		node = new_exec_node();
		if(!node)	
			return (*v_exec());
		node->cmd = ft_strdup(str);
		return (node);
	}
	else if(flag == 2)
	{
		cur->args[i] = ft_strdup(str);
		i++;
		return (cur);
	}
	else if(flag == 0)
	{
		cur->args[i] = NULL;
		i = 0;
		return (cur);
	}
	return (cur);
}
int	count_args(t_cmd *cmd)
{
	t_type type;
	int i;

	type = PIPE;
	i = 0;
	while (cmd && (cmd->type != type ))
	{
		i++;
		cmd = cmd->next;
	}
	return i;
}
// t_exec	*check_cmd(t_cmd **cmd, t_exec *list)
// {
// 	t_type type;

// 	type = PIPE;
// 	if((*cmd)->type & CMD)
// 	{
// 		if(list)
// 			list = list->next;
// 		list = add_to_exec_list((*cmd)->content, list, 1);
// 		while ((*cmd) && ((*cmd)->type != type))
// 		{
// 			if(!(list->args))
// 				list->args = ft_malloc(sizeof(char *) * count_args(*cmd));
// 			list = add_to_exec_list((*cmd)->content, list, 2);
// 			*cmd = (*cmd)->next;
// 		}
// 		list = add_to_exec_list(0, list, 0);
// 		lstadd_exec_back(v_exec(), list);
// 	}
// 	return list;
// }

// void fill_the_exec_struct(void)
// {
// 	t_cmd *cmd;
// 	t_exec *list;
	
// 	cmd = *v_cmd();
// 	list = *v_exec();
// 	while (cmd)
// 	{
// 		list = check_cmd(&cmd, list);
// 		fill_fds(*cmd, list);
// 		if(cmd)
// 			cmd = cmd->next;
// 	}
// }

void 	fill_the_exec_struct(void)
{
	t_cmd *tokens;
	t_exec *cmd;
	
	tokens = *v_cmd();
	cmd = new_exec_node();
	while(tokens)
	{
		fill_fds(tokens, cmd);
		fill_cmd(tokens, cmd);
		fill_args(tokens, cmd);
		if(tokens->type & PIPE)
		{
			lstadd_exec_back(v_exec(), cmd);
			cmd = new_exec_node();
		}
		tokens = tokens->next;
	}
}