/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 01:27:30 by imeslaki          #+#    #+#             */
/*   Updated: 2025/03/08 21:19:23 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init(t_data *data)
{
	data->pid1 = 1;
	data->pid2 = 1;
	data->fdin = -1;
	data->fdout = -1;
	data->absolute_path = NULL;
	data->full_cmd = NULL;
	data->cmd = NULL;
	data->cmd_path = NULL;
	data->exec = NULL;
	data->full_paths = NULL;
}
