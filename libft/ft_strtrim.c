/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 21:02:14 by imeslaki          #+#    #+#             */
/*   Updated: 2024/11/11 02:20:36 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	size_t	i;
	size_t	end;

	i = 0;
	if (s == NULL || set == NULL)
		return (NULL);
	end = ft_strlen(s);
	while (s[i] && ft_strchr(set, s[i]))
		i++;
	while (end > i && ft_strchr(set, s[end - 1]))
		end--;
	return (ft_substr(s, i, end - i));
}
