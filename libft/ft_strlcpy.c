/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:35:06 by ijoubair          #+#    #+#             */
/*   Updated: 2024/11/11 22:08:12 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;

	i = 0;
	srclen = ft_strlen(src);
	if (dstsize != 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srclen);
}
// int    main(void)
// {
// 	// char	*src = "";÷
// 	char	*dst;

// //    dst = "";
// //    dst = &src[2] ;
//    printf("%zu\n", strlcpy(dst, NULL, sizeof(dst)));
// //    printf("dst: %s\n", dst);
// //    printf("%zu\n", ft_strlcpy(dst, src, sizeof(src)));
// //    printf("dst: %s\n", dst);
// }
