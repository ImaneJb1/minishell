/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_dup_cmp_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 19:02:26 by imeslaki          #+#    #+#             */
/*   Updated: 2025/03/07 22:04:23 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_strdup_bonus(const char *s1)
{
	char	*dst;
	size_t	i;

	i = 0;
	dst = malloc(ft_strlen_bonus(s1) + 1);
	if (dst == NULL)
		return (NULL);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static char	*do_the_join(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*join;

	join = malloc(ft_strlen_bonus(s1) + ft_strlen_bonus(s2) + 1);
	if (join == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		join[i] = s2[j];
		i++;
		j++;
	}
	join[i] = '\0';
	return (join);
}

char	*ft_strjoin_bonus(char const *s1, char const *s2)
{
	char	*join;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup_bonus(s2));
	if (s2 == NULL)
		return (ft_strdup_bonus(s1));
	join = do_the_join(s1, s2);
	return (join);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	if (!str1 || !str2)
		return (0);
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_strncmp_bonus(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n && (str1[i] || str2[i]))
	{
		if (str1[i] != str2[i])
		{
			if (str1[i] < str2[i])
				return (-1);
			else
				return (1);
		}
		i++;
	}
	return (0);
}
