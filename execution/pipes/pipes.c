#include "../execution.h"

int		pipes(void)
{
	t_exec *cmd;
	int fd[2];
	int pid;
	int saved_stdin = dup(0);
	cmd = *v_exec();
	while(cmd)
	{
		if(pipe(fd) < 0)
			perror("");
		pid = fork();
		if(pid == 0)
			execute_commands(cmd, fd);
		dup2(fd[0], 0);
		close(fd[0]);
		close(fd[1]);
		wait(NULL);
		cmd = cmd->next;
	}
	dup2(saved_stdin ,0);
	return(0);
}
