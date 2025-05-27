/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_cmd_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:54:47 by ijoubair          #+#    #+#             */
/*   Updated: 2025/05/27 14:41:50 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

int		execution(t_exec *cmd) // HADI KHDAMA BIHA F SIMPLE COMMAND
{
	builtin(cmd);
	char **env = env_to_arr();
	if(!cmd->path && cmd->cmd)
	{
		print_cmd_error(cmd->cmd, "No such file or directory");
		exit(1);
	}
	if(!cmd->cmd)
		exit(1);
	dprintf(1,"here\n");
	// // dprintf(0,"here2\n");
	// dprintf(1,"arg = %s, %s\n",cmd->args[0], cmd->args[1]);
	// if(!env_to_arr()[0])
	// 	dprintf(1, "env is null\n");
	// dprintf(0,"cmd = %s   env = %s\n", cmd->path, env_to_arr()[0]);
	// dprintf(1,"in = %d   out = %d\n", cmd->fd_in, cmd->fd_out);
	execve(cmd->path, cmd->args, env);
	perror("execve");
	exit(1);
}

void	execute_first_command(t_exec *cmd, int *fd)
{
	printf("*******************first*****************\n");
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
	close(fd[1]);
	execution(cmd);
}

void	execute_middle_command(t_exec *cmd, int *fd)
{
	dprintf(2, "*******************middle*****************\n");
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
	dprintf(2,"*******************last*****************\n");
	close(fd[1]);
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
	execution(cmd);
}

void	execute_commands(t_exec *cmd, int *fd)
{
	if(cmd->prev == NULL)
		execute_first_command(cmd, fd);	
	else if(cmd->next == NULL)
		execute_last_command(cmd, fd);
	execute_middle_command(cmd, fd);
 }

