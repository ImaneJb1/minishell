/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocat_pipes_and_pid_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:07:24 by imeslaki          #+#    #+#             */
/*   Updated: 2025/03/08 03:10:26 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	**allocat_for_pipes(int number_of_pip)
{
	int	**pipes;
	int	i;

	i = 0;
	pipes = malloc(sizeof(int *) * (number_of_pip));
	if (!pipes)
	{
		perror("malloc");
		exit(1);
	}
	while (i < number_of_pip)
	{
		pipes[i] = malloc(sizeof(int) * 2);
		if (!pipes[i])
		{
			free_2d_arry_of_integers_bonus(pipes, i);
			perror("malloc");
			exit(1);
		}
		i++;
	}
	return (pipes);
}

int	*allocat_for_pid(int number_of_pid, t_data *data)
{
	int	*pid;

	pid = malloc(sizeof(int) * (number_of_pid + 1));
	if (!pid)
	{
		free_2d_arry_of_integers_bonus(data->pipes, data->number_of_loops);
		perror("malloc");
		exit(1);
	}
	return (pid);
}
