/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:54:47 by ijoubair          #+#    #+#             */
/*   Updated: 2025/05/22 10:19:05 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		execution(t_exec *cmd)
{
	//if its buitlin
	//else
	if(!cmd->path)
		print_cmd_error(cmd->cmd, "Command not found");
	execve(cmd->path, cmd->args, v_env());
}

void	execute_first_command(t_exec *cmd, int *fd)
{
	close(fd[0]);
	dup2(cmd->fd_in, 0);
	if(cmd->fd_in != 0)
		close(cmd->fd_in);
	if(cmd->fd_out != 1)
	{
		dup2(cmd->fd_out, 1);
		close(cmd->fd_out);
	}
	else
		dup2(fd[1], 1);
	execution(cmd);
}

void	execute_middle_command(t_exec *cmd, int *fd)
{
	close(fd[0]);
	if(cmd->fd_in != 0)
	{
		dup2(cmd->fd_in, 0);
		close(cmd->fd_in);
	}
	if(cmd->fd_out != 1)
	{
		dup2(cmd->fd_out, 1);
		close(cmd->fd_out);
	}
	else
		dup2(fd[1], 1);
	close(fd[1]);
	execution(cmd);
}

void	execute_last_comand(t_exec *cmd, int *fd)
{
	close(fd[0]);
	close(fd[1]);
	if(cmd->fd_in != 0)
	{
		dup2(cmd->fd_in, 0);
		close(cmd->fd_in);
	}
	if(cmd->fd_out != 1)
	{
		dup2(cmd->fd_out, 1);
		close(cmd->fd_out);
	}
	execution(cmd);
}

void	execute_commands(t_exec *cmd, int *fd)
{
	execute_first_command(cmd, fd);
	execute_middle_command(cmd, fd);
	execute_last_command(cmd, fd);
}

