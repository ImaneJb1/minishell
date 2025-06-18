#include "../execution.h"

void	exit_status_case(char *arg)
{
	if (ft_strcmp(arg, "$?") == 0)
	{
		printf("%d\n", g_exit_status);
		free_exit(0);
	}
}

void	pipes(void)
{
	t_exec	*cmd;
	int		fd[2];
	int		pid;
	int		saved_stdin;
	int		status;

	saved_stdin = dup(0);
	cmd = *v_exec();
	while (cmd)
	{
		if (pipe(fd) < 0)
			perror("");
		pid = fork();
		if (pid == 0)
			execute_commands(cmd, fd);
		dup2(fd[0], 0);
		close(fd[0]);
		close(fd[1]);
		cmd = cmd->next;
	}
	while (wait(&status) > 0)
		;
	dup2(saved_stdin, 0);
	g_exit_status = WEXITSTATUS(status);
	update_exit_status(g_exit_status);
}
