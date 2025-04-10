/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 20:46:09 by ijoubair          #+#    #+#             */
/*   Updated: 2024/11/07 18:47:17 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(long n)
{
	int	len;

	if (n > 0)
		len = 0;
	else
	{
		len = 1;
		n = -n;
	}
	while (n >= 1)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

void	ft_fill(char *s, int len, int i, long nb)
{
	while (--len >= i)
	{
		s[len] = nb % 10 + '0';
		nb = nb / 10;
	}
}

char	*ft_itoa(int n)
{
	char	*s;
	int		len;
	int		i;
	int		end;
	long	nb;

	nb = (long)n;
	i = 0;
	len = num_len(nb);
	end = len;
	s = malloc((len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	if (nb < 0)
	{
		nb = -nb;
		s[0] = '-';
		i++;
	}
	ft_fill(s, len, i, nb);
	s[end] = 0;
	return (s);
}
// #include <limits.h>

// int	main(void)
// {
// 	//    int a = -515;
// 	printf("%s\n", ft_itoa(INT_MIN));
// 	printf("%s\n", ft_itoa(INT_MAX));
// }