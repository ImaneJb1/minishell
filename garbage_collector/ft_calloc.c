/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 01:47:02 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/26 15:47:28 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"

void	ft_bzero(void *mem, size_t size)
{
	char	*s;
	size_t	i;

	if (!mem)
		return ;
	s = (char *)mem;
	i = 0;
	while (i < size)
	{
		*s = '\0';
		s++;
		i++;
	}
}

void	*ft_calloc_without_save(size_t n, size_t type_size)
{
	void	*mem;
	size_t	full_size;

	full_size = n * type_size;
	mem = malloc(full_size);
	if (!mem)
	{
		perror("minishell: ");
		ft_exit(1);
		return (NULL);
	}
	ft_bzero(mem, full_size);
	return (mem);
}

void	*ft_calloc(size_t n, size_t type_size)
{
	void	*mem;

	mem = ft_calloc_without_save(n, type_size);
	save_mem(mem);
	return (mem);
}

void	*ft_malloc(size_t n)
{
	return (ft_calloc(1, n));
}
