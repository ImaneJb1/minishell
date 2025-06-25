#include "execution.h"

void	main_execution(void)
{
	t_exec	*cmd;
	int		length;

	length = lstsize_exec();
	cmd = *v_exec();
	if (!cmd )
		return ;
	if (length == 1)
	{
		open_failure(0);
		execute_simple_cmd(cmd);

	}
	else
	{
		open_failure(0);
		pipes();
	}
}
