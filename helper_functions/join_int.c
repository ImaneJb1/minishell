/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 20:17:46 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/27 10:55:19 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

size_t	ft_intlen(int *array)
{
	size_t	i;

	i = 0;
	if (!array)
		return (0);
	while (array[i])
		i++;
	return (i);
}

int	*ft_int_dup(int *array, int len)
{
	int	i;
	int	*result;

	i = 0;
	result = ft_malloc(sizeof(int) * len);
	while (i < len)
	{
		result[i] = array[i];
		i++;
	}
	return (result);
}

int	get_size(int set)
{
	static int	size;

	if (set == 0)
		size = 0;
	if (set == 1)
		size++;
	return (size);
}

static int	reset_size(int set)
{
	if (set == 1)
	{
		get_size(0);
		return (1);
	}
	return (0);
}

void	index_the_char(int value, int i, int set)
{
	int	*result;
	int	**array;
	int	j;

	j = 0;
	if (reset_size(set))
		return ;
	array = v_array_index(0);
	if (*array == NULL)
	{
		*array = ft_malloc(sizeof(int));
		(*array)[0] = value;
		get_size(1);
		return ;
	}
	result = ft_malloc((sizeof(int) * (get_size(2) + 1)));
	while (j < get_size(2) && j < i)
	{
		result[j] = (*array)[j];
		j++;
	}
	result[j] = value;
	*array = result;
	get_size(1);
}
