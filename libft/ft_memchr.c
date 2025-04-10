/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:17:26 by imeslaki          #+#    #+#             */
/*   Updated: 2024/11/09 21:41:59 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*haystack;
	unsigned char		needle;
	size_t				i;

	i = 0;
	haystack = (unsigned const char *)s;
	needle = (unsigned char)c;
	while (i < n)
	{
		if (haystack[i] == needle)
			return ((void *)&haystack[i]);
		i++;
	}
	return (NULL);
}
