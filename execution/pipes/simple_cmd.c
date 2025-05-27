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
	int pid;

	// write(1,"out\n",4);
	// write(0,"in\n",3);
	pid = fork();
	// exit(0);
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

void	simple_cmd(void)
{
	t_exec	*cmd;

	cmd = *v_exec();
	execute_cmd(cmd);
	
}