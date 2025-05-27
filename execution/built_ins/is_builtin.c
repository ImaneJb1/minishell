#include "built_in.h"

void fd_exit(t_exec *node)
{
	(void)node;
	ft_free_all();
	exit(1);
}

void	builtin(t_exec *cmd)
{	
	static t_buitin arr[4]={{"echo", echo}, {"cd", cd}, {"pwd", pwd},
		{"exit", fd_exit}};
	int i;
	i = 0;
	while(i < 4)
	{
		if(ft_strcmp(arr[i].cmd, cmd->cmd) == 0)
		{
			arr[i].func(cmd);
			exit(0);
		}
		i++;
	}
}
