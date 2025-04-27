/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_char_in_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:07:46 by imeslaki          #+#    #+#             */
/*   Updated: 2025/04/23 21:07:39 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

char	*insert_char_str(char *str, char ch, int i)
{
	int		j;
	int		v;
	char	*string;

	v = 0;
	string = NULL;
	if (!str || i < 0)
		return (NULL);
	j = ft_strlen(str);
	if (i > j)
		i = j;
	string = ft_malloc(j + 1);
	j = 0;
	while (str[v] && j < i)
		string[j++] = str[v++];
	string[j++] = ch;
	while (str[v])
		string[j++] = str[v++];
	return (string);
}
