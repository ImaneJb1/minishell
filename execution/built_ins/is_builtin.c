#include "built_in.h"

void	builtin(t_exec *cmd)
{	
	static t_buitin arr[3]={{"echo", echo}, {"cd", cd}, {"pwd", pwd}};
	int i;
	i = 0;
	while(i < 3)
	{
		if(ft_strcmp(arr[i].cmd, cmd->cmd) == 0)
		{
			arr[i].func(cmd);
			exit(0);
		}
		i++;
	}
}
