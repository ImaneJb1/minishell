/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2d_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:41:48 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/15 09:26:31 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

void	*free_2d_arry(char **ptr)
{
	size_t	i;

	i = 0;
	while (ptr[i] != NULL)
	{
		ft_free(ptr[i]);
		i++;
	}
	ft_free(ptr);
	return (NULL);
}
