/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 00:39:48 by ijoubair          #+#    #+#             */
/*   Updated: 2024/11/05 14:46:04 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_set(int *arr, char const *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		arr[(unsigned int)s[i]] = 1;
		i++;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		tmp;
	int		arr[256];
	char	*trim;

	j = 0;
	ft_bzero(arr, 256);
	i = 0;
	if (!s1 || !set)
		return (NULL);
	ft_set(arr, set);
	i = 0;
	while (s1[i] && arr[(unsigned int)s1[i]] == 1)
		i++;
	tmp = i;
	while (s1[i])
		i++;
	i--;
	while (i >= 0 && arr[(unsigned int)s1[i]] == 1)
		i--;
	trim = ft_substr(s1, tmp, i - tmp + 1);
	return (trim);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*s;

// 	s = ft_strtrim("cnnnnnnbghguyuygggjbbbbb", "abc");
// 	printf("%s", s);
// 	free(s);
// }
