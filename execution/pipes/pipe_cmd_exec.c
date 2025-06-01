/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_cmd_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:54:47 by ijoubair          #+#    #+#             */
/*   Updated: 2025/05/31 22:39:36 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

void	execution(t_exec *cmd) // HADI KHDAMA BIHA F SIMPLE COMMAND
{
	char **env = env_to_arr();
	
	builtin(cmd);
	if (opendir(cmd->cmd))
	{
		print_cmd_error(cmd->cmd, "is a directory");
		ft_exit(errno);
	}
	execve(cmd->path, cmd->args, env); //   cat => /cat => /usr/bin/cat => access(path, F_OK | X_OK)
	if (errno == EACCES) {
        fprintf(stderr, "minishell: %s: Permission denied\n", cmd->cmd);
        ft_exit(126);  
    } else if (errno == ENOENT) {
        fprintf(stderr, "minishell: %s: command not found\n", cmd->cmd);
        ft_exit(127);  
    } else {
        perror("execve");
        ft_exit(1);    // Other errors
    }
}

void	execute_first_command(t_exec *cmd, int *fd)
{
	close(fd[0]);
	if (cmd->fd_in != 0)
	{
		dup2(cmd->fd_in, 0); 
		close(cmd->fd_in);
	}
	if (cmd->fd_out != 1)
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
	close(fd[0]);
	if (cmd->fd_in != 0)
	{
		dup2(cmd->fd_in, 0);
		close(cmd->fd_in);
	}
	if (cmd->fd_out != 1)
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
	dprintf(2, "*******************last*****************\n");
	close(fd[1]);
	close(fd[0]);
	if (cmd->fd_in != 0)
	{
		dup2(cmd->fd_in, 0);
		close(cmd->fd_in);
	}
	if (cmd->fd_out != 1)
	{
		dup2(cmd->fd_out, 1);
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
