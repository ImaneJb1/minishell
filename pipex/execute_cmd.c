/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 01:45:31 by imeslaki          #+#    #+#             */
/*   Updated: 2025/03/08 02:03:50 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_cmd(char *arg, t_data *data, char **env)
{
	execve(data->absolute_path, data->full_cmd, env);
	free(data->absolute_path);
	free_2d_arry(data->full_cmd);
	errors(arg, data, -1);
}
