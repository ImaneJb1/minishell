/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_and_close_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:26:16 by imeslaki          #+#    #+#             */
/*   Updated: 2025/03/08 03:45:08 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	dup_close_first_cmd_bonus(t_data *data)
{
	close(data->pipes[0][0]);
	data->pipes[0][0] = -1;
	dup2(data->fdin, 0);
	close(data->fdin);
	data->fdin = -1;
	dup2(data->pipes[0][1], 1);
	close(data->pipes[0][1]);
	data->pipes[0][1] = -1;
	return ;
}

void	dup_close_last_cmd_bonus(t_data *data)
{
	dup2(data->pipes[data->cur_loop - 1][0], 0);
	close(data->pipes[data->cur_loop - 1][0]);
	data->pipes[data->cur_loop - 1][0] = -1;
	dup2(data->fdout, 1);
	close(data->fdout);
	data->fdout = -1;
	return ;
}

void	dup_close_middle_cmds_bonus(t_data *data)
{
	close(data->pipes[data->cur_loop][0]);
	data->pipes[data->cur_loop][0] = -1;
	dup2(data->pipes[data->cur_loop - 1][0], 0);
	close(data->pipes[data->cur_loop - 1][0]);
	data->pipes[data->cur_loop - 1][0] = -1;
	dup2(data->pipes[data->cur_loop][1], 1);
	close(data->pipes[data->cur_loop][1]);
	data->pipes[data->cur_loop][1] = -1;
	return ;
}

void	dup_close_one_cmd_bonus(t_data *data)
{
	dup2(data->fdin, 0);
	close(data->fdin);
	data->fdin = -1;
	dup2(data->fdout, 1);
	close(data->fdout);
	data->fdout = -1;
}
