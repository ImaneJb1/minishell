/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 23:48:43 by ijoubair          #+#    #+#             */
/*   Updated: 2024/11/12 14:19:10 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;
	char	*p;
	size_t	i;
	size_t	o;

	o = count * size;
	if (size && o / size != count)
		return (NULL);
	arr = malloc(count * size);
	if (!arr)
		return (NULL);
	p = (char *)arr;
	i = 0;
	while (i < count * size)
	{
		p[i] = 0;
		i++;
	}
	return (arr);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%d", *(int*) ft_calloc(1, 1));
}
*/