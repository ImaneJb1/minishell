/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_the_exec_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:20:25 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/14 11:49:59 by imeslaki         ###   ########.fr       */
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
		node->cmd = ft_strdup(str);
		return (node);
	}
	else if(flag == 2)
	{
		if(!cur)
			return (*v_exec());
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

t_exec	*check_cmd(t_cmd **cmd, t_exec *list)
{
	t_type type;

	type = PIPE;
	if((*cmd)->type | CMD)
	{
		if(list)
			list = list->next;
		list = add_to_exec_list((*cmd)->content, list, 1);
		while ((*cmd) && ((*cmd)->type != type))
		{
			fill_fds(cmd, list);
			if(!(list->args))
				list->args = ft_malloc(sizeof(char *) * count_args(*cmd));
			list = add_to_exec_list((*cmd)->content, list, 2);
			*cmd = (*cmd)->next;
		}
		list = add_to_exec_list(0, list, 0);
	}
	return list;
}
