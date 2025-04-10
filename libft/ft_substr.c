/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:09:04 by imeslaki          #+#    #+#             */
/*   Updated: 2024/11/09 23:30:30 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	str_len;
	char	*mal;

	if (s == NULL)
		return (NULL);
	str_len = ft_strlen(s);
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
