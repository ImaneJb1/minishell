/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 01:47:18 by imeslaki          #+#    #+#             */
/*   Updated: 2025/04/12 16:47:50 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"

void	ft_exit(int status)
{
	ft_free_all();
	ft_destory_all();
	return ;
}

void	*current_working_mem(void *mem, int set_to_null)
{
	static void	*working_mem;

	if (set_to_null)
		working_mem = NULL;
	if (mem)
		working_mem = mem;
	return (working_mem);
}
