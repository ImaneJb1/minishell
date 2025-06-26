#include "built_in.h"

void	builtin(t_exec *cmd)
{
	static t_buitin	arr[7] = {{"echo", echo}, {"cd", cd}, {"pwd", pwd},
	{"exit", exit_func}, {"export", export}, {"env", env}, {"unset", unset}};
	int				i;

	i = 0;
	while (i < 7)
	{
		if (ft_strcmp(arr[i].cmd, cmd->cmd) == 0)
		{
			arr[i].func(cmd);
			free_exit(g_exit_status);
		}
		i++;
	}
}
