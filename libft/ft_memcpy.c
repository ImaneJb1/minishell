/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:13:22 by ijoubair          #+#    #+#             */
/*   Updated: 2024/11/05 10:57:31 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*tmpd;
	unsigned char	*tmps;

	tmpd = (unsigned char *)dest;
	tmps = (unsigned char *)src;
	if (tmpd == NULL && tmps == NULL)
		return (NULL);
	while (n > 0)
	{
		*tmpd = *tmps;
		tmpd++;
		tmps++;
		n--;
	}
	return (dest);
}
