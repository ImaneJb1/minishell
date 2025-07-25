/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen_2d_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:41:48 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/16 15:16:43 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

int	strlen_2d_array(char **ptr)
{
	size_t	i;

	i = 0;
	if (!ptr)
		return (0);
	while (ptr[i] != NULL)
		i++;
	return (i);
}
