/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:45:29 by ijoubair          #+#    #+#             */
/*   Updated: 2025/05/11 16:39:57 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

int	ft_strcmp(char *s1, char *s2)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	if((s1 && !s2) || (s2 && !s1))
		return 1;
	if(!s1 && !s2)
		return 0;
	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	while ((*tmp1 != '\0' || *tmp2 != '\0'))
	{
		if (*tmp1 != *tmp2)
			return (1);
		tmp1++;
		tmp2++;
	}
	return (0);
}
