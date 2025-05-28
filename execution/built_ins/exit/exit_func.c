#include "../built_in.h"

bool	is_numeric_arg(char *arg)
{
	int i;

	i = 0;
	while(arg[i])
	{
		if(ft_isdigit(arg[i]) == 0)
			return(FALSE);
		i++;
	}
	return(TRUE);
}

void exit_func(t_exec *node)
{
	if(!node->args)
	{
		ft_free_all();
		exit(0); // exit status of the last command
	}
	else if(node->args[1] && !node->args[2])
	{
		if(is_numeric_arg(node->args[1]))
			exit(atoi(node->args[1]));
		else
		{
			write(1, "exit: ", 6);
			print_cmd_error(node->args[1], "numeric argument required");
		}
	}
	else
	{
		write(1, "exit: ", 6);
		print_cmd_error(node->args[1], "too many arguments");
	}
}
