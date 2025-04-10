/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 12:57:44 by ijoubair          #+#    #+#             */
/*   Updated: 2024/11/02 22:34:55 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)s;
	while (n > 0)
	{
		if (*tmp == (unsigned char)c)
			return (tmp);
		tmp++;
		n--;
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	int	s[4] = {1,8,5,5};
	int	c;
	int	*arr;
	int	i;

	c = 8;
	arr = ft_memchr(s, c, 8);
	i = 0;
	if (arr == NULL)
	{
		printf("NULL");
		return (0);
	}
	//printf("%s", arr);
	while(i <= 4)
	{
	printf("%d ", arr[i]);
	i++;
	}
}
*/
