/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_env_linked_list2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:17:58 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/23 16:42:54 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	lstclear_env(void)
{
	t_env	*cur;
	t_env	*next;

	cur = *v_env();
	if (!cur)
		return ;
	while (cur)
	{
		next = cur->next;
		ft_free(cur->key);
        ft_free(cur->value);
		ft_free(cur);
		cur = next;
	}
	*v_env() = NULL;
}

void	lstadd_one_env_by_node(t_env	*new, t_env	*cur)
{
	if(!cur && cur->prev)
		return;
	else if(!cur->next)
	{
		lstadd_env_back(v_env(), new);
		cur->prev = new;
		new->next = cur;
	}
	else
	{
		new->next = cur;
		new->prev = cur->prev;
		if(!cur->prev)
			*v_env() = new;
		else
			(cur->prev)->next = new;
		cur->prev = new;
	}
}

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

