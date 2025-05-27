#include "execution.h"

void	main_execution(void)
{
	t_exec *cmd;
	int		length;

	length = lstsize_exec();
	cmd = *v_exec();
	if(length == 1)
		simple_cmd();
	else
		pipes();
}