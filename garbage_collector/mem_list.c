/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 01:47:53 by imeslaki          #+#    #+#             */
/*   Updated: 2025/03/25 01:47:55 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"

t_mem_list	**ft_mem_list(void)
{
	static t_mem_list	*list;

	return (&list);
}

t_mem_list	**ft_img_list(void)
{
	static t_mem_list	*list;

	return (&list);
}
