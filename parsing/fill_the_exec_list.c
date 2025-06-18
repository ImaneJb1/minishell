/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_the_exec_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:20:25 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/17 19:10:29 by imeslaki         ###   ########.fr       */
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

void	fill_node(t_cmd *tokens, t_exec **cmd)
{
	fill_fds_into_exec(tokens, cmd);
	fill_args(tokens, cmd);
	fill_cmd(tokens, cmd);
}

int	is_ambiguous(t_exec *cmd, t_cmd *save_token)
{
	cmd = add_to_exec_list(NULL, cmd, 0);
	if (is_redirection(save_token))
	{
		ft_putstr_fd("bash: ambiguous redirect\n", STDERR_FILENO);
		return (0);
	}
	return (1);
}

t_exec	*next_exec_node(t_exec *cmd)
{
	not_first_cmd(0);
	lstadd_exec_back(v_exec(), cmd);
	add_to_exec_list(NULL, cmd, 0);
	cmd = new_exec_node();
	return (cmd);
}

int	fill_the_exec_struct(void)
{
	t_cmd	*tokens;
	t_exec	*cmd;
	t_cmd	*save_token;

	if (!v_cmd() || !(*v_cmd()))
		return (0);
	tokens = *v_cmd();
	cmd = new_exec_node();
	while (tokens)
	{
		fill_node(tokens, &cmd);
		if (is_error(2))
			return (handle_exec_error());
		inside_child(0);
		if (tokens->type & PIPE)
			cmd = next_exec_node(cmd);
		save_token = tokens;
		tokens = tokens->next;
	}
	if (!is_ambiguous(cmd, save_token))
		return (0);
	lstadd_exec_back(v_exec(), cmd);
	not_first_cmd(0);
	field_count_arg(0);
	return (1);
}
