/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_str_in_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:01:06 by imeslaki          #+#    #+#             */
/*   Updated: 2025/04/27 17:29:03 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

char    *insert_str_str(char *str, char  *insert, int index)
{
	int		i;
	int		j;
	int		v;
	char	*string;

	i = 0;
    v = 0;
	string = NULL;
    if(index < 0)
        return NULL;
	else if (!str)
		return (ft_strdup(insert));
	else if (!insert)
		return (ft_strdup(str));
	j = ft_strlen(str) + ft_strlen(insert);
	string = ft_malloc(j + 1);
	j = 0;
	while (str[i] && i < index)
		string[j++] = str[i++];
	while (insert[v])
		string[j++] = insert[v++];
    while (str[i])
		string[j++] = str[i++];
	return (string);
}
