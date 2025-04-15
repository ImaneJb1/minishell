/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 01:12:22 by imeslaki          #+#    #+#             */
/*   Updated: 2025/03/08 02:07:23 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_2(char **av, t_data *data, char **env)
{
	if (data->pip[0] < 0)
		exit(1);
	data->fdout = creat_fdout(av[4], data);
	data->absolute_path = get_the_absolute_path(av[3], data, env);
	data->full_cmd = ft_split(av[3], ' ');
	if (!data->full_cmd)
		return (errors(av[2], data, data->fdin));
	close_and_dup(data, 2);
	execute_cmd(av[3], data, env);
}

void	cmd_1(char **av, t_data *data, char **env)
{
	data->fdin = creat_fdin(av[1], data);
	data->absolute_path = get_the_absolute_path(av[2], data, env);
	data->full_cmd = ft_split(av[2], ' ');
	if (!data->full_cmd)
		return (errors(av[2], data, data->fdin));
	close_and_dup(data, 1);
	execute_cmd(av[2], data, env);
}

int	main(int ac, char **av, char **env)
{
	t_data	data;

	init(&data);
	if (ac == 5)
	{
		if (pipe(data.pip) == -1)
			errors("pipe", &data, -1);
		data.pid1 = fork();
		if (data.pid1 != 0)
			data.pid2 = fork();
		if (data.pid1 < 0 || data.pid2 < 0)
			errors("fork", &data, -1);
		if (data.pid1 == 0)
			cmd_1(av, &data, env);
		else if (data.pid2 == 0)
			cmd_2(av, &data, env);
		else
			wait_function(&data);
	}
	write(2, "invalid number of argument\n", 27);
	return (1);
}
