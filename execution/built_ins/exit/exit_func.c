#include "../built_in.h"

bool	is_numeric_arg(char *arg)
{
	int	i;

	i = 0;
	if(arg[i] == 0)
		return(FALSE);
	if(arg[i] == '-' || arg[i] == '+')
		i++;
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
	{
		print_msg_to_fd("exit\n", NULL, NULL, 1);
		free_exit(g_exit_status);
	}
	else if (node->args[1])
	{
		if (is_numeric_arg(node->args[1]))
		{
			if(!node->args[2])
			{
				write(1, "exit\n", 5);
				free_exit(ft_atoi(node->args[1]));
			}
			else
			{
				update_exit_status(1);
				print_msg_to_fd("exit\n", "minishell: exit: ", "too many arguments\n", 2);
			}
		}
		else
		{
			print_msg_to_fd("exit\nminishell: exit: ", node->args[1], " numeric argument required\n", 2);
			free_exit(2);
		}
	}
}
