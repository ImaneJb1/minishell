/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_errors_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 01:58:57 by imeslaki          #+#    #+#             */
/*   Updated: 2025/03/07 23:32:35 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_all(t_data *data)
{
	if (data->absolute_path)
		free(data->absolute_path);
	if (data->full_cmd)
		free_2d_arry_bonus(data->full_cmd);
	if (data->pipes && data->number_of_loops > 0)
		free_2d_arry_of_integers_bonus(data->pipes, data->number_of_loops);
	if (data->pid)
		free(data->pid);
}

void	free_2d_arry_of_integers_bonus(int **ptr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	free_2d_arry_bonus(char **ptr)
{
	size_t	i;

	i = 0;
	while (ptr[i] != NULL)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	errors_bonus(char *str, t_data *data, int fd)
{
	if (fd != -1)
	{
		data->fdin = 3;
		close(fd);
	}
	if (str[0] == '\0')
		perror("\'\'");
	else
		perror(str);
	exit(127);
}
