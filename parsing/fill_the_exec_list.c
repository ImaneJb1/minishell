/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_the_exec_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:20:25 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/21 10:49:21 by ijoubair         ###   ########.fr       */
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
		if(cur && cur->args && cur->args[0])
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
		if(cmd->type & (CMD_ARG | CMD))
			i++;
		cmd = cmd->next;
	}
	return i;
}
// t_exec	*check_cmd(t_cmd **cmd, t_exec *list)
// {
// 	t_type type;

void fill_cmd(t_cmd *token, t_exec **cmd)
{
	if(token->type & CMD)
	{
		*cmd = add_to_exec_list(token->content, *cmd, 1);
		(*cmd)->args = ft_malloc(sizeof(char *) * (count_args(token) + 1));
		*cmd = add_to_exec_list(token->content, *cmd, 2);
	}
}

void	fill_args(t_cmd *token, t_exec **cmd)
{
	if(token->type & CMD_ARG)
		*cmd = add_to_exec_list(token->content, *cmd, 2);
}
void 	fill_the_exec_struct(void)
{
	t_cmd *tokens;
	t_exec *cmd;
	
	if(!v_cmd() || !(*v_cmd()))
        return ;
	tokens = *v_cmd();

	cmd = new_exec_node();
	while(tokens)
	{
		fill_fds(tokens, &cmd);
		fill_cmd(tokens, &cmd);
		fill_args(tokens, &cmd);
		if(tokens->type & PIPE)
		{
			lstadd_exec_back(v_exec(), cmd);
			cmd = add_to_exec_list(NULL, cmd, 0);
			cmd = new_exec_node();
		}
		tokens = tokens->next;
	}
	if(cmd)
		cmd = add_to_exec_list(NULL, cmd, 0);
	lstadd_exec_back(v_exec(), cmd);
}
