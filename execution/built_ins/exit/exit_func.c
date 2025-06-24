#include "../built_in.h"

bool	is_numeric_arg(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (ft_isdigit(arg[i]) == 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	exit_func(t_exec *node)
{
	if (!node->args || !node->args[1])
		free_exit(0); // exit status of the last command
	else if (node->args[1])
	{
		if (is_numeric_arg(node->args[1]))
		{
			if(!node->args[2])
				free_exit(ft_atoi(node->args[1]));
			else
			{
				print_msg_to_fd("exit\n", "minishell: exit: ", "too many arguments\n", 2);
				// print_cmd_error(node->args[1], "too many arguments");
			}
		}
		else
		{
			print_msg_to_fd("exit\n", "minishell: ", "exit: ", 2);
			print_cmd_error(node->args[1], "numeric argument required");
			free_exit(2);
		}
	}
}
