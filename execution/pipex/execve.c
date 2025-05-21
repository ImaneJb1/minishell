/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:54:47 by ijoubair          #+#    #+#             */
/*   Updated: 2025/05/21 17:06:02 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		execution(t_exec *cmd)
{
	//if its buitlin
	//else
	//findpath
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
	//execute
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
	//execute
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
}

void	execute_commands(t_exec *cmd, int *fd)
{
	//execute_first_command
}


int		pipex(void)
{
	t_exec *cmd;
	int fd[2];
	int pid;
	
	cmd = v_exec();
	while(cmd)
	{
		if(pipe(fd) < 0)
			perror("");
		pid = fork();
		if(pid == 0)
			//execute
		dup2(fd[0], 0);
		close(fd[0]);
		close(fd[1]);
		cmd = cmd->next;
	}
}