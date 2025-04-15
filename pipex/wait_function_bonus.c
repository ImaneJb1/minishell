/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_function_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 03:26:25 by imeslaki          #+#    #+#             */
/*   Updated: 2025/03/10 19:53:14 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	wait_function_bonus(int *pid, int max)
{
	int	i;
	int	status;
	int	exit_status;

	status = 0;
	exit_status = 0;
	i = 0;
	while (i < max - 1)
	{
		waitpid(pid[i], 0, 0);
		i++;
	}
	waitpid(pid[i], &status, 0);
	if (WIFEXITED(status))
		exit_status = WEXITSTATUS(status);
	free(pid);
	unlink("here_doc");
	exit(exit_status);
}
