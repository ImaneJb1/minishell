/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_pipes_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:36:42 by imeslaki          #+#    #+#             */
/*   Updated: 2025/03/08 03:08:50 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	close_pipes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_loops && (data->pipes[i][0] != -1
		&& data->pipes[i][1] != -1))
	{
		close(data->pipes[i][0]);
		data->pipes[i][0] = -1;
		close(data->pipes[i][1]);
		data->pipes[i][1] = -1;
		i++;
	}
}
