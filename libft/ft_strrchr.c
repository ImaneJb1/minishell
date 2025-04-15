/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:26:57 by imeslaki          #+#    #+#             */
/*   Updated: 2024/11/05 03:41:19 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	last;

	last = 0;
	while (str[last])
		last++;
	while (last >= 0)
	{
		if (str[last] == (char)c)
			return ((char *)&str[last]);
		last--;
	}
	return (NULL);
}
