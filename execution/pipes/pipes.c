#include "../execution.h"

void	exit_status_case(char *arg)
{
	if (ft_strcmp(arg, "$?") == 0)
	{
		printf("%d\n", g_exit_status);
		free_exit(0);
	}
}

void	wait_func(int saved_stdin)
{
	int		status;
	t_exec	*cmd;
	
	cmd = *v_exec();
	while (cmd)
	{
		waitpid(cmd->pid, &status, 0);
		cmd = cmd->next;
	}
	g_exit_status = WEXITSTATUS(status);
	dup2(saved_stdin, 0);
	update_exit_status(g_exit_status);
}

void	pipes(void)
{
	t_exec	*cmd;
	int		fd[2];
	int		saved_stdin;

	saved_stdin = dup(0);
	cmd = *v_exec();
	while (cmd)
	{
		if (pipe(fd) < 0)
			perror("minishell :");
		cmd->pid = fork();
		if (cmd->pid == 0)
			execute_commands(cmd, fd);
		dup2(fd[0], 0);
		close(fd[0]);
		close(fd[1]);
		cmd = cmd->next;
	}
	wait_func(saved_stdin);
}
