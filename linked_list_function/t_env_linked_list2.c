/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_env_linked_list2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:17:58 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/12 15:50:23 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	lst_del_one_env_by_node(t_env	*cur)
{
	
	t_env	*tmp;

	if(!*v_env())
		return ;
	if(!(*v_env())->next)
	{
		*v_env() = NULL;
		return ;
	}
	tmp = cur;
	if(cur->prev)
	{
		(cur->prev)->next = cur->next;
		if(cur->next)
			(cur->next)->prev = cur->prev;
	}
	else
	{
		*v_env() = cur->next;
		(cur->next)->prev = NULL;
	}
	ft_free(tmp);
}

