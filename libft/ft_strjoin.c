/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 00:06:29 by ijoubair          #+#    #+#             */
/*   Updated: 2024/11/05 11:00:13 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*s3;
	int		i;
	int		j;

	len = ft_strlen(s1) + ft_strlen(s2);
	s3 = malloc(len * sizeof(char) + 1);
	if (!s3)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
	{
		s3[i++] = s1[j++];
	}
	j = 0;
	while (s2[j])
	{
		s3[i++] = s2[j++];
	}
	s3[i] = '\0';
	return (s3);
}
// #include <stdio.h>
// int main()
// {
//     char *s = ft_strjoin("imane", " fatihhh");
//     printf("%s\n", s);
//     free(s);
// }
