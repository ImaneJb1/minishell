#include "./pipex.h"

int		pipex(void)
{
	t_exec *cmd;
	int fd[2];
	int pid;
	
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
		cmd = cmd->next;
	}
	//khsni ndir loop fel parent katsed ga3 fd's li f exec list
}
