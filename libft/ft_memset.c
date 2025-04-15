/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:00:05 by imeslaki          #+#    #+#             */
/*   Updated: 2024/11/16 15:19:33 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*t;
	size_t			i;

	t = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		t[i] = (unsigned char)c;
		i++;
	}
	return ((void *)t);
}
// int main ()
// {
// 	int i;
// 	ft_memset(&i,128,4);
// 	ft_memset(&i,0,3);

// 	printf("%d",i);

// }