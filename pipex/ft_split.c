/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 10:07:00 by imeslaki          #+#    #+#             */
/*   Updated: 2025/03/09 19:36:29 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_count(char const *s, char c)
{
	size_t	i;
	size_t	count;
	int		check;

	count = 0;
	i = 0;
	check = 0;
	while (s && s[i])
	{
		if (s[i] != c && check == 0)
		{
			check = 1;
			count++;
		}
		if (s[i] == c)
			check = 0;
		i++;
	}
	return (count);
}

static size_t	ft_countlen(char const *s, char c, size_t i)
{
	size_t	count;

	count = 0;
	while (s[i] && s[i] != c)
	{
		count++;
		i++;
	}
	return (count);
}

void	*free_2d_arry(char **ptr)
{
	size_t	i;

	i = 0;
	while (ptr[i] != NULL)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t(i) = 0, (j) = 0;
	char **(ptr);
	if (!s)
		return (NULL);
	ptr = malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!ptr)
		return (NULL);
	while (s && s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		ptr[j] = ft_substr(s, i, ft_countlen(s, c, i));
		if (ptr[j] == NULL)
			return (free_2d_arry(ptr), NULL);
		j++;
		while (s[i] && s[i] != c)
			i++;
	}
	ptr[j] = NULL;
	return (ptr);
}
