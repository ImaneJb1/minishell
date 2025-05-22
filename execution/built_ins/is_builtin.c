#include "built_in.h"

void	builtin(t_exec *cmd)
{
	static t_buitin arr[]={{"echo", echo}, {"cd", cd}, {"pwd", pwd}};
	int i;
	int len = sizeof(arr)/sizeof(arr[0]);
	i = 0;
	while(i < len)
	{
		if(ft_strcmp(arr[i].cmd, cmd->cmd) == 0)
			arr[i].func(cmd);
		i++;
	}
}
