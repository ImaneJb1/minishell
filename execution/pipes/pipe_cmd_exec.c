/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_cmd_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:54:47 by ijoubair          #+#    #+#             */
/*   Updated: 2025/06/26 19:14:30 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

void	execution(t_exec *cmd)
{
	if (cmd->cmd == NULL)
		free_exit(0);
	builtin(cmd);
	if (ft_strchr(cmd->cmd, '/') && opendir(cmd->cmd))
	{
		print_proc_error("minishell: ", cmd->cmd, ": is a directory\n", 2);
		ft_exit(126);
	}
	execve(cmd->path, cmd->args, env_to_arr());
	print_execve_errors(cmd);
}

void	execute_first_command(t_exec *cmd, int *fd)
{
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	if (cmd->fd_in != STDIN_FILENO)
	{
		dup2(cmd->fd_in, STDIN_FILENO);
		close(cmd->fd_in);
	}
	if (cmd->fd_out != STDOUT_FILENO)
	{
		dup2(cmd->fd_out, STDOUT_FILENO);
		close(cmd->fd_out);
	}
	close(fd[1]);
	execution(cmd);
}

void	execute_middle_command(t_exec *cmd, int *fd)
{
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	if (cmd->fd_in != STDIN_FILENO)
	{
		dup2(cmd->fd_in, STDIN_FILENO);
		close(cmd->fd_in);
	}
	if (cmd->fd_out != STDOUT_FILENO)
	{
		dup2(cmd->fd_out, STDOUT_FILENO);
		close(cmd->fd_out);
	}
	close(fd[1]);
	execution(cmd);
}

void	execute_last_command(t_exec *cmd, int *fd)
{
	close(fd[1]);
	close(fd[0]);
	if (cmd->fd_in != STDIN_FILENO)
	{
		if (dup2(cmd->fd_in, STDIN_FILENO) < 0)
			free_exit(1);
		close(cmd->fd_in);
	}
	if (cmd->fd_out != 1)
	{
		if (dup2(cmd->fd_out, STDOUT_FILENO) < 0)
			free_exit(1);
		close(cmd->fd_out);
	}
	execution(cmd);
}

void	execute_commands(t_exec *cmd, int *fd)
{
	if (cmd->prev == NULL)
		execute_first_command(cmd, fd);
	else if (cmd->next == NULL)
		execute_last_command(cmd, fd);
	execute_middle_command(cmd, fd);
}
