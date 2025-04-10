/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:23:44 by ijoubair          #+#    #+#             */
/*   Updated: 2024/11/08 22:24:00 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	while ((*tmp1 != '\0' || *tmp2 != '\0') && n > 0)
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
// 	const char	*s1 = "test\200";
// 	const char	*s2 = "test\0";
// 	int			n ;

// 	n = 0;
// 	printf("for n = %d\nexpected: %d\n",n ,strncmp(s1, s2, n));
// 	printf("Got: %d", ft_strncmp(s1, s2, n));
// }
