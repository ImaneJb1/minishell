/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 01:12:30 by imeslaki          #+#    #+#             */
/*   Updated: 2025/03/08 02:20:04 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	errors(char *str, t_data *data, int fd)
{
	if (fd != -1)
	{
		close(fd);
		close(data->pip[0]);
		close(data->pip[1]);
	}
	if (str[0] == '\0')
		perror("\'\'");
	else
		perror(str);
	exit(1);
}
