/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:07:27 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/18 18:43:11 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing/parsing.h"

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

void	print_msg_to_fd(char *s1, char *s2, char *s3, int fd)
{
	ft_putstr_fd(s1, fd);
	ft_putstr_fd(s2, fd);
	ft_putstr_fd(s3, fd);
}

int	fd_error(t_exec *cmd)
{
	if (cmd->fd_in < 0)
		return (1);
	if (cmd->fd_out < 0)
		return (1);
	return (0);
}

void	print_execve_errors(t_exec *cmd)
{
	if (errno == EACCES)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(cmd->cmd, STDERR_FILENO);
		ft_putstr_fd(": Permission denied\n", STDERR_FILENO);
		ft_exit(126);
	}
	else if (errno == ENOENT)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(cmd->cmd, STDERR_FILENO);
		if (ft_strchr(cmd->cmd, '/') || is_paht_empty(0))
			ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
		else
			ft_putstr_fd(": command not found\n", STDERR_FILENO);
		ft_exit(127);
	}
	else
	{
		perror("execve");
		ft_exit(1);
	}
}
