/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 21:27:58 by ijoubair          #+#    #+#             */
/*   Updated: 2024/11/08 14:29:01 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmpdst;
	unsigned char	*tmpsrc;
	int				x;

	tmpdst = (unsigned char *)dst;
	tmpsrc = (unsigned char *)src;
	x = 1;
	if (!src && !dst)
		return (NULL);
	if (src < dst)
	{
		x = -1;
		tmpdst = tmpdst + len - 1;
		tmpsrc = tmpsrc + len - 1;
	}
	while (len-- > 0)
	{
		*tmpdst = *tmpsrc;
		tmpdst = tmpdst + x;
		tmpsrc = tmpsrc + x;
	}
	return (dst);
}

// int	main(void)
// {
// 	char	s[] = "hello";
// 	size_t	len;

// 	len = 6;
// 	printf("%s",ft_memmove(s + 2, s, len));
// 	printf("\n%lu", sizeof(s));

// }