/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:58:57 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/31 16:21:45 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

static int	ft_count(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		j;
	long	nbr;

	nbr = n;
	j = ft_count(nbr);
	str = ft_malloc(j + 1);
	if (!str)
		return (NULL);
	if (nbr == 0)
		str[0] = '0';
	str[j] = '\0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = nbr * -1;
	}
	while (nbr != 0)
	{
		str[--j] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (str);
}
