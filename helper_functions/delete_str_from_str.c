/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_str_from_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:36:44 by imeslaki          #+#    #+#             */
/*   Updated: 2025/04/22 15:18:22 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

char	*del_str_str(char *str, char *del)
{
	int		i;
	int		j;
	int		v;
	char	*string;

	i = 0;
	string = NULL;
	if (!str)
		return ((char *)NULL);
	if (!del)
		return (ft_strdup(str));
	j = ft_strlen(str);
	string = ft_malloc(j);
	j = 0;
	v = ft_strnstr(str, del);
	if (v < 0)
		return (ft_strdup(str));
	while (i < v)
		string[j++] = str[i++];
	if (str[i])
		i += (ft_strlen(del));
	while (str[i])
		string[j++] = str[i++];
	return (string);
}
