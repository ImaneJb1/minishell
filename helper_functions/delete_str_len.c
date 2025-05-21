/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_str_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:44:27 by imeslaki          #+#    #+#             */
/*   Updated: 2025/04/27 18:10:06 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

char	*del_str_len(char *str, size_t start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	x;
	char	*string;

	i = 0;
	string = NULL;
	if (!str)
		return (NULL);
	j = ft_strlen(str);
	string = ft_malloc(j + 1);
	j = 0;
	while (str[i] && j < start)
		string[j++] = str[i++];
	x = i;
	while (str[i] && i < x + len)
		i++;
	while (str[i])
		string[j++] = str[i++];
	return (string);
}
