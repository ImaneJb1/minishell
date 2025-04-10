/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:09:32 by imeslaki          #+#    #+#             */
/*   Updated: 2024/11/16 14:13:14 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	dst_index;
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	dst_index = dstlen;
	if (dstsize <= dstlen)
		return (dstsize + srclen);
	while (src[i] && dst_index < dstsize - 1)
	{
		dst[dst_index] = src[i];
		i++;
		dst_index++;
	}
	dst[dst_index] = '\0';
	return (dstlen + srclen);
}
// int main ()
// {
// 	printf("%zu",ft_strlcat("NULL","NULL",4));
// }