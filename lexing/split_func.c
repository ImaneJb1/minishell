/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:56:01 by ijoubair          #+#    #+#             */
/*   Updated: 2025/04/11 00:05:42 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.h"

char	check_flag(int *flag, char c, int *i, char const *s)
{
	if (*flag == 1)
	{
		c = ' ';
		*flag = 0;
		(*i)++;
	}
	if (s[*i] == '\"' || s[*i] == '\'')
	{
		if (*flag == 0)
		{
			*flag = 1;
			c = s[*i];
			(*i)++;
		}
	}
	return (c);
}

char	**super_split(char const *s, char c)
{
	char	**ptr;

	int (i), (j), (flag);
	flag = 0;
	i = 0;
	j = 0;
	ptr = malloc(sizeof(char *) * (super_count(s, c) + 1));
	if (!ptr)
		return (NULL);
	while (s && s[i])
	{
		c = check_flag(&flag, c, &i, s);
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		c = check_flag(&flag, c, &i, s);
		ptr[j] = ft_substr(s, i, super_countlen(s, c, i));
		if (ptr[j] == NULL)
			return (super_free_2d_arry(ptr));
		j++;
		while (s[i] && s[i] != c)
			i++;
	}
	return ((ptr[j] = NULL), ptr);
}
