/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:28:07 by ijoubair          #+#    #+#             */
/*   Updated: 2024/11/12 14:48:06 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	j;
	size_t	lendst;

	if (dstsize == 0 || ft_strlen(dst) >= dstsize)
		return (dstsize + ft_strlen(src));
	lendst = ft_strlen(dst);
	j = 0;
	while (j < dstsize - lendst - 1 && src[j])
	{
		dst[lendst + j] = src[j];
		j++;
	}
	dst[lendst + j] = '\0';
	return (ft_strlen(src) + lendst);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// int	main(void)
// {
//    char dest[200];
//    char dest2[200];
// 	printf("%zu\n", ft_strlcat(NULL, "hello", 0));
//    //write(1, "\n", 1);
//    //write(1, dest, 15);
// }
