/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:46:48 by imeslaki          #+#    #+#             */
/*   Updated: 2025/04/27 17:08:36 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t i;
	unsigned char *str1;
	unsigned char *str2;

	i = 0;
	if (!s1 || !s2)
		return (0);
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n && (str1[i] || str2[i]))
	{
		if (str1[i] != str2[i])
		{
			if (str1[i] < str2[i])
				return (-1);
			else
				return (1);
		}
		i++;
	}
	return (0);
}