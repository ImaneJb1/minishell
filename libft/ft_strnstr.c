/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:23:58 by ijoubair          #+#    #+#             */
/*   Updated: 2024/11/11 21:57:38 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	if (((ft_strlen(haystack) == 0 && ft_strlen(needle) == 0))
		|| ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		k = 0;
		while (needle[k] && haystack[i + k] == needle[k] && k + i < len)
			k++;
		if (needle[k] == '\0')
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}

//#include <stdio.h>
//
//int	main(void)
//{
//	char haystack[30] = "aaxx";
//	char needle[10] = "xx";
//	char		*ptr1;
//	char		*ptr2;
//
//	ptr1 = ft_strnstr(haystack, needle,	3);
//	ptr2 = strnstr(haystack, needle, 3);
//	printf("Got: %s\n", ptr1);
//	printf("Expected: %s\n", ptr2);
//}
