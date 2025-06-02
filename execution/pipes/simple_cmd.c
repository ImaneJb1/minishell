#include "../execution.h"

void	dup_and_close(t_exec *cmd)
{
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

bool	handle_export_unset(t_exec *cmd)
{
	static t_buitin arr[5]={{"cd", cd}, {"pwd", pwd},
		{"exit", exit_func}, {"export", export}, {"unset", unset}};
	int i;
	i = 0;
	while(i < 5)
	{
		if(ft_strcmp(arr[i].cmd, cmd->cmd) == 0)
		{
			arr[i].func(cmd);
			return(TRUE);
		}
		i++;
	}
	return(FALSE);
}

void	execute_simple_cmd(t_exec *cmd)
{
	int pid;
	int	status;

	if(handle_export_unset(cmd))
		return;
	else
	{
		pid = fork();
		if(pid == 0)
		{
			dup_and_close(cmd);
			execution(cmd);
		}
		if(cmd->fd_in != 0)
			close(cmd->fd_in);
		if(cmd->fd_out != 1)
			close(cmd->fd_out);
		waitpid(pid, &status, 0);
	}
	update_exit_status(WEXITSTATUS(status));
}

void	simple_cmd(void)
{
	t_exec	*cmd;

	cmd = *v_exec();
	execute_simple_cmd(cmd);
}