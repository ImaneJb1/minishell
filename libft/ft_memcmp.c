/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:39:12 by imeslaki          #+#    #+#             */
/*   Updated: 2024/11/14 23:12:52 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*cmp1;
	const unsigned char	*cmp2;
	size_t				i;

	cmp1 = (const unsigned char *)s1;
	cmp2 = (const unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (cmp1[i] != cmp2[i])
			return (cmp1[i] - cmp2[i]);
		i++;
	}
	return (0);
}
