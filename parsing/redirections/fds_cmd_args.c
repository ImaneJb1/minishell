/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fds_cmd_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:10:29 by ijoubair          #+#    #+#             */
/*   Updated: 2025/06/27 10:07:12 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

int	count_args(t_cmd *cmd)
{
	t_type	type;
	int		i;

	type = PIPE;
	i = 0;
	while (cmd && (cmd->type != type))
	{
		if (cmd->type & (CMD_ARG | CMD))
			i++;
		cmd = cmd->next;
	}
	return (i);
}

void	fill_cmd(t_cmd *token, t_exec **cmd)
{
	if ((token->type & CMD) && !not_first_cmd(2))
	{
		not_first_cmd(1);
		*cmd = add_to_exec_list(token->content, *cmd, 1);
		(*cmd)->args = ft_malloc(sizeof(char *) * (count_args(token) + 1));
		*cmd = add_to_exec_list(token->content, *cmd, 2);
		fill_path(*cmd);
	}
}

void	fill_args(t_cmd *token, t_exec **cmd)
{
	if ((token->type & CMD_ARG) && not_first_cmd(2))
	{
		*cmd = add_to_exec_list(token->content, *cmd, 2);
	}
}

void	fill_fds_into_exec(t_cmd *token, t_exec **node)
{
	int	failure;

	failure = open_failure(-1);
	open_fd_heredoc(token, &(*node)->fd_in);
	if (failure == 0)
	{
		if (open_fd_out(token, node) < 0 || open_fd_app(token, node) < 0 || \
			open_fd_in(token, &(*node)->fd_in) < 0)
			open_failure(1);
	}
}
