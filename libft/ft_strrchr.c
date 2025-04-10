/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:41:24 by ijoubair          #+#    #+#             */
/*   Updated: 2024/11/11 21:58:47 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	f;

	f = -1;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			f = i;
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	if (f == -1)
		return (NULL);
	return ((char *)&s[f]);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(int argc, char **argv)
{
	(void)argc;
	printf("Got: %s\n", ft_strrchr(argv[1],argv[2][0]));
	printf("expected: %s\n", strrchr(argv[1],argv[2][0]));
}
*/