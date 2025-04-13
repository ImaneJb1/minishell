/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:56:01 by ijoubair          #+#    #+#             */
/*   Updated: 2025/04/11 18:57:48 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.h"

char	check_flag(int *flag, int *i, char const *s)
{
	if (*flag == 1)
	{
		*flag = 0;
		return '\0';
	}
	if (s[*i] == '\"' || s[*i] == '\'')
	{
		if (*flag == 0)
		{
			*flag = 1;
			return '\0';
		}
	}
	return ('|');
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
		c = check_flag(&flag, &i, s);
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		c = check_flag(&flag, &i, s);
		ptr[j] = ft_substr(s, i, super_countlen(s, c, i));
		if (ptr[j] == NULL)
			return (super_free_2d_arry(ptr));
		j++;
		while (s[i] && s[i] != c)
			i++;
	}
	return ((ptr[j] = NULL), ptr);
}
// "< file cat | ls |||||a| echo \"hello |||||| m \" "