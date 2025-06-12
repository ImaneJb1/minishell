/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cmd_linked_list_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imane <imane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:32:18 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/12 18:55:21 by imane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	lstclear_cmd(void)
{
	t_cmd	*cur;
	t_cmd	*next;

	cur = *v_cmd();
	if (!cur)
		return ;
	while (cur)
	{
		next = cur->next;
		ft_free(cur->content);
		ft_free(cur);
		cur = next;
	}
	*v_cmd() = NULL;
}

void	lst_add_one_cmd(t_cmd *cur, t_cmd *new)
{
	t_cmd	*next;

	next = cur->next;
	if (!cur || !cur->next)
	{
		lstadd_cmd_back(v_cmd(), new);
		// cur->prev = new;
		// new->next = cur;
	}
	else
	{
		cur->next = new;
		new->prev = cur;
		new->next = next;
		next->prev = new;
		// new->next = cur;
		// new->prev = cur->prev;
	}
}

void	lst_del_one_cmd(t_cmd *cur)
{
	if (!*v_cmd())
		return ;
	if (!(*v_cmd())->next)
	{
		*v_cmd() = NULL;
		return ;
	}
	if (cur->prev)
	{
		(cur->prev)->next = cur->next;
		if (cur->next)
			(cur->next)->prev = cur->prev;
	}
	else
	{
		*v_cmd() = cur->next;
		(cur->next)->prev = NULL;
	}
}

