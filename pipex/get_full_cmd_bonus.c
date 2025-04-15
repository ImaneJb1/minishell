/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_full_cmd_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 08:16:42 by imeslaki          #+#    #+#             */
/*   Updated: 2025/03/02 17:05:24 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**get_full_cmd_bonus(char *arg, t_data *data)
{
	data->full_cmd = ft_split_bonus(arg, ' ');
	if (!data->full_cmd)
	{
		free_all(data);
		errors_bonus(arg, data, data->fdin);
	}
	return (data->full_cmd);
}
