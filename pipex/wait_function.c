/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 01:19:48 by imeslaki          #+#    #+#             */
/*   Updated: 2025/03/08 03:26:11 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	wait_function(t_data *data)
{
	int	status;
	int	exit_status;

	status = 0;
	exit_status = 0;
	close(data->pip[1]);
	waitpid(data->pid1, 0, 0);
	waitpid(data->pid2, &status, 0);
	if (WIFEXITED(status))
		exit_status = WEXITSTATUS(status);
	exit(exit_status);
}
