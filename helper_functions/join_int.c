/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 20:17:46 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/24 18:59:08 by imeslaki         ###   ########.fr       */
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

int	*ft_int_dup(int *array, int len)
{
	int i;
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

void    index_the_char(int  value, int i, int set)
{
	int	*result;
	static int size;
    int **array;
    int j;

    j = 0;
	if(set == 1)
	{
		size = 0;
		return ;
	}
    array = v_array_index(0); // echo '$?'
	if (*array == NULL)		  // 0000 00
	{
		*array = ft_malloc(sizeof(int));
		(*array)[0] = value;
		size++;
		return ;
	}
	result = ft_malloc((sizeof(int) * (size + 1)));
	while (j < size && j < i)
	{
		result[j] = (*array)[j];
	    j++;
	}
	result[j] = value;
    *array = result;
	size++;
	return ;
}
