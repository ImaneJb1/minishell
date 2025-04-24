/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_str_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:44:27 by imeslaki          #+#    #+#             */
/*   Updated: 2025/04/22 15:08:08 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

char    *del_str_len(char   *str, int start, size_t len)
{
	int		i;
	int		j;
	int 	x;
	char	*string;

	i = 0;
	string = NULL;
	if (!str || start < 0)
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
