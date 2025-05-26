/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_cmd_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:54:47 by ijoubair          #+#    #+#             */
/*   Updated: 2025/05/26 14:23:17 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

int		execution(t_exec *cmd)
{
	builtin(cmd);

	if(!cmd->path)
		print_cmd_error(cmd->path, "No such file or directory");
	execve(cmd->path, cmd->args, env_to_arr());// env must be char **
	print_cmd_error(cmd->path, "Failed");
	exit(1);
}

void	execute_first_command(t_exec *cmd, int *fd)
{
	(void)fd;
	// close(fd[0]);
	// dup2(cmd->fd_in, 0);
	// if(cmd->fd_in != 0)
	// 	close(cmd->fd_in);
	// if(cmd->fd_out != 1)
	// {
	// 	dup2(cmd->fd_out, 1);
	// 	close(cmd->fd_out);
	// }
	// else
	// 	dup2(fd[1], 1);	
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

void	execute_last_command(t_exec *cmd, int *fd)
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
// 	execute_middle_command(cmd, fd);
// 	execute_last_command(cmd, fd);
 }

