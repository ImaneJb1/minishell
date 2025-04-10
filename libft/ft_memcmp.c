/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:34:58 by ijoubair          #+#    #+#             */
/*   Updated: 2024/11/08 21:34:24 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*tmp1 != *tmp2)
			return (*tmp1 - *tmp2);
		tmp1++;
		tmp2++;
		n--;
	}
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*s1;
// 	char	*s2;

// 	s1 = "imaane";
// 	s2 = "ib";
// 	printf("got: %d\n", ft_memcmp(s1, s2, 50));
// 	printf("expected: %d", memcmp(s1, s2, 50));
// }
