/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:30:44 by ijoubair          #+#    #+#             */
/*   Updated: 2024/10/31 13:17:52 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
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
		printf("Got: %c\n",ft_toupper(atoi(argv[1])));
		printf("expected: %c\n",toupper(atoi(argv[1])));
	}
}
*/
