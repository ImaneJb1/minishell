/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:58:21 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/27 11:01:42 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing/parsing.h"

int	fd_error(t_exec *cmd)
{
	if (open_failure(-1) == 1)
		return (1);
	if (cmd->fd_in < 0)
		return (1);
	if (cmd->fd_out < 0)
		return (1);
	return (0);
}

int	is_error(int flag)
{
	static int	i;

	if (flag == 0)
		i = 0;
	else if (flag == 1)
		i = 1;
	return (i);
}

int	handle_exec_error(void)
{
	not_first_cmd(0);
	is_error(0);
	field_count_arg(0);
	return (0);
}
