/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_cmd_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:54:47 by ijoubair          #+#    #+#             */
/*   Updated: 2025/06/18 18:21:07 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

void	print_errors(t_exec *cmd)
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
		if(ft_strchr(cmd->cmd,'/'))
			ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
		else
			ft_putstr_fd(": command not found\n", STDERR_FILENO);
        ft_exit(127);  
    } 
	else
	{
        perror("");
        ft_exit(1);
    }
}

void	execution(t_exec *cmd) // HADI KHDAMA BIHA F SIMPLE COMMAND
{
	builtin(cmd);
	if (opendir(cmd->cmd))
	{
		print_cmd_error(cmd->cmd, "is a directory");
		ft_exit(126);
	}
	execve(cmd->path, cmd->args, env_to_arr()); //   cat => /cat => /usr/bin/cat => access(path, F_OK | X_OK)
	print_errors(cmd);
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
		if(dup2(cmd->fd_out, STDOUT_FILENO) < 0)
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
