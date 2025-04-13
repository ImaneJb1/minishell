/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:20:10 by imeslaki          #+#    #+#             */
/*   Updated: 2025/03/08 03:09:42 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	execut_childs(char **av, t_data *data, char **env)
{
	while (data->cur_loop < data->number_of_loops - 1)
	{
		if (pipe(data->pipes[data->cur_loop]) == -1)
		{
			free_all(data);
			perror("pipe");
			exit(1);
		}
		data->pid[data->cur_loop] = fork();
		if (data->pid[data->cur_loop] == 0)
			child_proccess(av, data, env);
		else
		{
			if (data->cur_loop > 0)
			{
				close(data->pipes[data->cur_loop - 1][0]);
				data->pipes[data->cur_loop - 1][0] = -1;
			}
			close(data->pipes[data->cur_loop][1]);
			data->pipes[data->cur_loop][1] = -1;
			data->cur_loop++;
		}
	}
}

void	last_child(char **av, t_data *data, char **env)
{
	data->pid[data->cur_loop] = fork();
	if (data->pid[data->cur_loop] == 0)
		child_proccess(av, data, env);
	else
	{
		close(data->pipes[data->cur_loop - 1][0]);
		data->pipes[data->cur_loop - 1][0] = -1;
	}
}

void	child_proccess(char **av, t_data *data, char **env)
{
	if (data->cur_loop == 0)
	{
		data->fdin = creat_fdin_bonus(av[1], data);
		dup_close_first_cmd_bonus(data);
	}
	else if (data->cur_loop == (data->last_cmd - 2))
	{
		data->fdout = creat_fdout_bonus(av[data->last_cmd + 1], data,
				data->cur_loop);
		dup_close_last_cmd_bonus(data);
	}
	else
		dup_close_middle_cmds_bonus(data);
	data->absolute_path = get_absolute_path_bonus(av[data->cur_loop + 2], data,
			env);
	data->full_cmd = get_full_cmd_bonus(av[data->cur_loop + 2], data);
	execute_cmd_bonus(av[data->cur_loop + 2], data, env);
}

void	execute_cmd_bonus(char *arg, t_data *data, char **env)
{
	execve(data->absolute_path, data->full_cmd, env);
	free_all(data);
	errors_bonus(arg, data, -1);
}
