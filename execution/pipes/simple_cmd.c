/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:31:36 by ijoubair          #+#    #+#             */
/*   Updated: 2025/06/27 10:29:20 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

void	dup_and_close(t_exec *cmd)
{
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
}

bool	handle_export_unset(t_exec *cmd)
{
	int				i;
	static t_buitin	arr[6] = {{"cd", cd}, {"echo", echo}, {"pwd", pwd},
	{"exit", exit_func}, {"export", export}, {"unset", unset}};

	i = 0;
	while (i < 6)
	{
		if (ft_strcmp(arr[i].cmd, cmd->cmd) == 0)
		{
			arr[i].func(cmd);
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

void	signal_msg_and_exit_status(int status)
{
	int	signal;

	signal = WTERMSIG(status);
	if (signal == SIGQUIT)
		ft_putstr_fd("Quit (core dumped)\n", STDERR_FILENO);
	else if (signal == SIGINT)
		ft_putstr_fd("\n", STDERR_FILENO);
	update_exit_status((128 + signal));
}

void	parent_proccess_in_simple_cmd(t_exec *cmd, int pid)
{
	int	status;

	is_path_empty(0);
	if (cmd->fd_in != 0)
		close(cmd->fd_in);
	if (cmd->fd_out != 1)
		close(cmd->fd_out);
	inside_child(1);
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status))
		signal_msg_and_exit_status(status);
	else if (WIFEXITED(status))
		update_exit_status(WEXITSTATUS(status));
	inside_child(0);
}

void	execute_simple_cmd(t_exec *cmd)
{
	int	pid;

	if (fd_error(cmd) || handle_export_unset(cmd))
		return ;
	else
	{
		open_failure(0);
		signal(SIGINT, SIG_IGN);
		pid = fork();
		if (pid == 0)
		{
			signal(SIGQUIT, SIG_DFL);
			signal(SIGINT, SIG_DFL);
			dup_and_close(cmd);
			execution(cmd);
		}
		parent_proccess_in_simple_cmd(cmd, pid);
		signal(SIGINT, handle_sig_int);
	}
}
