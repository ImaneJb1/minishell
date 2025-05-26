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


void	execute_cmd(t_exec *cmd)
{
	// int pid;

	// pid = fork();
	// if(pid == 0)
	// {
		dup_and_close(cmd);
		builtin(cmd);
		execution(cmd);
	// }
	if(cmd->fd_in != 0)
		close(cmd->fd_in);
	if(cmd->fd_out != 1)
		close(cmd->fd_out);
	wait(NULL);
}

void	simple_cmd(void)
{
	t_exec	*cmd;

	cmd = *v_exec();
	execute_cmd(cmd);
	
}