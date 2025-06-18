/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cmd_linked_list_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:32:18 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/17 19:07:06 by imeslaki         ###   ########.fr       */
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
	}
	else
	{
		cur->next = new;
		new->prev = cur;
		new->next = next;
		next->prev = new;
	}
}

void	lst_del_one_cmd(t_cmd *cur)
{
	t_cmd	*tmp;

	if (!*v_cmd())
		return ;
	if (!(*v_cmd())->next)
	{
		*v_cmd() = NULL;
		return ;
	}
	tmp = cur;
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
