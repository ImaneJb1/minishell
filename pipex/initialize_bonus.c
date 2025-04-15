/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 03:30:11 by imeslaki          #+#    #+#             */
/*   Updated: 2025/03/08 21:19:53 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	init(t_data *data)
{
	data->number_of_loops = 0;
	data->number_of_pipes = 0;
	data->last_cmd = 0;
	data->cur_loop = 0;
	data->pipes = 0;
	data->pid = 0;
	data->fdin = -1;
	data->fdout = -1;
	data->absolute_path = NULL;
	data->full_cmd = NULL;
	data->cmd = NULL;
	data->cmd_path = NULL;
	data->exec = NULL;
	data->full_paths = NULL;
}
