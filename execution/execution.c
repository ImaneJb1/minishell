#include "execution.h"

void	main_execution(void)
{
	t_exec	*cmd;
	int		length;

	length = lstsize_exec();
	cmd = *v_exec();
	if (!cmd || !cmd->cmd)
		return ;
	if (length == 1)
		execute_simple_cmd(cmd);
	else
		pipes();
}
