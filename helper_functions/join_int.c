/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 20:17:46 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/23 22:41:39 by imeslaki         ###   ########.fr       */
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

// int *init_array_index(char *str)
// {
//     // ft_
    
// }

// void    index_the_char(int  value, int i)
// {
//     int *array;

//     array = v_array_index();
// 	array[i] = value;
// }



void    index_the_char(int  value, int i)
{
	int	*result;
    int **array;
    int j;

    j = 0;
    array = v_array_index(0);
	if (*array == NULL)
	{
		*array = ft_malloc(sizeof(int) * 1);
		(*array)[0] = value;
		return ;
	}
	result = ft_malloc((sizeof(int) * (i + 1)));
	while (j < i)
	{
		result[j] = (*array)[j];
	    j++;
	}
	result[j] = value;
    *array = result;
	return ;
}
/*
0
0
1
0

*/