/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_cmd_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:54:47 by ijoubair          #+#    #+#             */
/*   Updated: 2025/05/27 11:29:09 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

int		execution(t_exec *cmd) // HADI KHDAMA BIHA F SIMPLE COMMAND
{
	char **env;
	
	env_to_arr();
	env = *env_arr();
	builtin(cmd);
	if(!cmd->path)
	{
		print_cmd_error(cmd->cmd, "No such file or directory");
		exit(1);
	}
	if(execve(cmd->path, cmd->args, env) < 0)
		perror("");
	return(0);
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

