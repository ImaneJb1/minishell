/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 11:00:30 by imeslaki          #+#    #+#             */
/*   Updated: 2025/03/09 20:12:11 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	no_cmd(char **av, t_data *data)
{
	char	*content;

	content = NULL;
	data->fdin = creat_fdin_bonus(av[1], data);
	data->fdout = creat_fdout_bonus(av[2], data, -1);
	content = get_next_line(data->fdin, NULL);
	while (content)
	{
		write_in_file(content, data->fdout);
		free(content);
		content = get_next_line(data->fdin, NULL);
	}
	free(content);
}

void	one_cmd(char **av, t_data *data, char **env)
{
	int	id;
	int	status;
	int	exit_status;

	status = 0;
	exit_status = 0;
	id = -1;
	id = fork();
	if (id == 0)
	{
		creat_fd_for_onecmd_bonus(av[1], av[3], data);
		dup_close_one_cmd_bonus(data);
		data->absolute_path = get_absolute_path_bonus(av[2], data, env);
		data->full_cmd = get_full_cmd_bonus(av[2], data);
		execute_cmd_bonus(av[2], data, env);
	}
	else
	{
		waitpid(id, &status, 0);
		if (WIFEXITED(status))
			exit_status = WEXITSTATUS(status);
		exit(exit_status);
	}
}

char	**here_doc_handle(int *ac, char **av, t_data *data)
{
	int	i;

	i = 2;
	data->delemiter = av[2];
	while (av[i + 1])
	{
		av[i] = av[i + 1];
		i++;
	}
	data->fdin = here_doc(av[1], data);
	av[i] = NULL;
	(*ac)--;
	return (av);
}

void	multiple_pipes(char **av, t_data *data, char **env)
{
	data->pipes = allocat_for_pipes(data->number_of_loops);
	data->pid = allocat_for_pid(data->number_of_loops + 1, data);
	execut_childs(av, data, env);
	last_child(av, data, env);
	close_pipes(data);
	free_2d_arry_of_integers_bonus(data->pipes, data->number_of_loops);
	if (data->pid[data->cur_loop])
		wait_function_bonus(data->pid, data->number_of_loops);
}

int	main(int ac, char **av, char **env)
{
	t_data	data;

	init(&data);
	if (ft_strcmp(av[1], "here_doc") == 1)
		av = here_doc_handle(&ac, av, &data);
	data.number_of_loops = ac - 3;
	data.last_cmd = ac - 2;
	if (ac == 3)
	{
		no_cmd(av, &data);
		exit(0);
	}
	else if (ac == 4)
		one_cmd(av, &data, env);
	else if (ac > 4)
		multiple_pipes(av, &data, env);
	write(2, "invalid number of argument\n", 27);
	return (1);
}
