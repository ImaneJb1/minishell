/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:36:09 by imeslaki          #+#    #+#             */
/*   Updated: 2024/11/15 01:30:35 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;
	size_t	res;

	res = count * size;
	if (count != 0 && res / count != size)
		return (NULL);
	s = malloc(count * size);
	if (!s)
		return (NULL);
	ft_memset(s, 0, count * size);
	return (s);
}
// int main()
// {
//    int i = 0;
//    int *ptr;
//    size_t x = 9223372036854775807;

//     printf("%s\n", ft_calloc(x, 2));
//     printf("%s\n", calloc(x, 2));
// }