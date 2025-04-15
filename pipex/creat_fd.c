/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 01:36:34 by imeslaki          #+#    #+#             */
/*   Updated: 2025/03/09 19:53:16 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	creat_fdin(char *arg, t_data *data)
{
	data->fdin = open(arg, O_RDONLY, 0666);
	if (data->fdin < 0)
	{
		close(data->pip[1]);
		errors(arg, data, -1);
	}
	return (data->fdin);
}

int	creat_fdout(char *arg, t_data *data)
{
	data->fdout = open(arg, O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (data->fdout < 0)
	{
		close(data->pip[0]);
		perror(arg);
		exit(1);
	}
	return (data->fdout);
}
