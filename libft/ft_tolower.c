/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:19:46 by ijoubair          #+#    #+#             */
/*   Updated: 2024/10/31 13:24:12 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}
/*#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	if(argc > 1)
	{
		printf("Got: %c\n",ft_tolower(atoi(argv[1])));
		printf("expected: %c\n",tolower(atoi(argv[1])));
	}
}
*/