/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_char_from_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:20:44 by imeslaki          #+#    #+#             */
/*   Updated: 2025/04/22 15:18:29 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

char	*del_char_str_index(char *str, int i)
{
	int		j;
	int		v;
	char	*string;

	v = 0;
	string = NULL;
	if (!str || i < 0)
		return (NULL);
	j = ft_strlen(str);
	if (i > j - 1)
		i = j - 1;
	string = ft_malloc(j + 1);
	j = 0;
	while (str[v] && j < i)
		string[j++] = str[v++];
	if (str[v])
		v++;
	while (str[v])
		string[j++] = str[v++];
	return (string);
}
