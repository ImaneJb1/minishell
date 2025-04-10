/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:57:46 by ijoubair          #+#    #+#             */
/*   Updated: 2024/11/05 21:48:17 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		i;

	dup = malloc(ft_strlen(s1) + 1);
	i = 0;
	if (!dup)
		return (NULL);
	while (s1[i])
	{
		dup[i] = (char)s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%s", ft_strdup("imaaannnee"));
}
*/