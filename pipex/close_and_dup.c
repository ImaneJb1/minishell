/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_and_dup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 01:23:49 by imeslaki          #+#    #+#             */
/*   Updated: 2025/03/08 01:24:10 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_and_dup(t_data *data, int flage)
{
	if (flage == 1)
	{
		close(data->pip[0]);
		dup2(data->fdin, 0);
		close(data->fdin);
		dup2(data->pip[1], 1);
		close(data->pip[1]);
		return ;
	}
	else if (flage == 2)
	{
		close(data->pip[1]);
		dup2(data->pip[0], 0);
		close(data->pip[0]);
		dup2(data->fdout, 1);
		close(data->fdout);
		return ;
	}
	return ;
}
