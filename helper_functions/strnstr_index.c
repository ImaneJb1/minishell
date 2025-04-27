/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:23:09 by imeslaki          #+#    #+#             */
/*   Updated: 2025/04/27 17:08:46 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

int	ft_strnstr(char *haystack, char *needle)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*needle == '\0')
	{
		return (i);
	}
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j] && haystack[i + j])
		{
			j++;
		}
		if (needle[j] == '\0')
		{
			return (i);
		}
		i++;
	}
	return (-1);
}
