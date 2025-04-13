/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 19:00:20 by imeslaki          #+#    #+#             */
/*   Updated: 2025/02/23 10:57:06 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	*ft_allocat(char const *s, unsigned char start, size_t len)
{
	size_t	i;
	char	*mal;

	i = 0;
	mal = malloc(len + 1);
	if (mal == NULL)
		return (NULL);
	while (i < len)
	{
		mal[i] = s[start + i];
		i++;
	}
	mal[i] = '\0';
	return (mal);
}

char	*ft_substr_bonus(char const *s, unsigned int start, size_t len)
{
	size_t	str_len;
	char	*mal;

	if (s == NULL)
		return (NULL);
	str_len = ft_strlen_bonus(s);
	if (start >= str_len)
	{
		mal = malloc(1);
		if (!mal)
			return (NULL);
		mal[0] = '\0';
		return (mal);
	}
	if (start + len > str_len)
		len = str_len - start;
	mal = ft_allocat(s, start, len);
	return (mal);
}
