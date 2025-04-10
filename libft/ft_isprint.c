/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:08:36 by ijoubair          #+#    #+#             */
/*   Updated: 2024/11/08 14:27:30 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if ((c >= 0 && c <= 31) || (c == 127) || (!(c >= 0 && c <= 127)))
		return (0);
	return (1);
}
// #include <ctype.h>
// int	main(void)
// {
// 	int	a;

// 	scanf("%d", &a);
// 	printf("expected: %d\n", isprint(a));
// 	printf("got: %d", ft_isprint(a));
// }
