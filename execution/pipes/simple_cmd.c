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

void fd_exit(t_exec *node)
{
	(void)node;
	ft_free_all();
	exit(1);
}
bool	handle_export_unset(t_exec *cmd)
{
	static t_buitin arr[5]={{"cd", cd}, {"pwd", pwd},
		{"exit", fd_exit}, {"export", export}, {"unset", unset}};
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
		wait(NULL);
	}
}

void	simple_cmd(void)
{
	t_exec	*cmd;

	cmd = *v_exec();
	execute_simple_cmd(cmd);
	
}