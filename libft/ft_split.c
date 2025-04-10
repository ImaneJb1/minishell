/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:01:38 by ijoubair          #+#    #+#             */
/*   Updated: 2024/11/12 14:43:32 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_counter(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s && s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static int	length_counter(char const *s, char c, int i)
{
	int	count;

	count = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		count++;
	}
	return (count);
}

char	**free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		word_count;
	int		i;
	int		j;
	char	**arr;

	i = 0;
	j = 0;
	word_count = word_counter(s, c);
	arr = malloc((word_count + 1) * sizeof(char *));
	if (!arr || !s)
		return (free(arr), NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			arr[j] = ft_substr(s, i, length_counter(s, c, i));
			if (!arr[j++])
				return (free_arr(arr));
		}
		while (s[i] && s[i] != c)
			i++;
	}
	return (arr[j] = NULL, arr);
}

// int main()
// {
//     int i;
//     char **arr =  ft_split("imane test  ", ' ');

//     i = 0;
//     while (arr[i])
//     {
//         printf("%s", arr[i]);
//         i++;
//     }
// }
