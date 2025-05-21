/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cmd_linked_list_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:32:18 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/18 19:10:24 by imeslaki         ###   ########.fr       */
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

t_cmd	*find_cmd_by_index(int index)
{
	t_cmd	*cur;
	cur = *v_cmd();
	while(cur)
	{
		if(cur->index == index)
			break;	
		cur = cur->next;
	}
	return cur;
}

void	lst_add_one_cmd_by_node(t_cmd	*cur, t_cmd	*new)
{
	t_cmd *next;

	next = cur->next;
	if(!cur || !cur->next)
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

// void	lst_add_one_cmd(t_cmd	*new, int index)
// {
// 	t_cmd	*cur;

// 	cur = find_cmd_by_index(index);
// 	if(!cur && cur->prev)
// 		return;
// 	else if(!cur->next)
// 	{
// 		lstadd_cmd_back(v_cmd(), new);
// 		cur->prev = new;
// 		new->next = cur;
// 	}
// 	else
// 	{
// 		new->next = cur;
// 		new->prev = cur->prev;
// 		if(!cur->prev)
// 			*v_cmd() = new;
// 		else
// 			(cur->prev)->next = new;
// 		cur->prev = new;
// 	}
// 	index_the_cmd_list();
// }

void	lst_del_one_cmd_by_node(t_cmd	*cur)
{
	t_cmd	*tmp;

	if(!*v_cmd())
		return ;
	if(!(*v_cmd())->next)
	{
		*v_cmd() = NULL;
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
		*v_cmd() = cur->next;
		(cur->next)->prev = NULL;
	}
	ft_free(tmp);
}

// void	lst_del_one_cmd(int index)
// {
// 	t_cmd	*cur;
// 	t_cmd	*tmp;

// 	if(!*v_cmd())
// 		return ;
// 	if(!(*v_cmd())->next)
// 	{
// 		*v_cmd() = NULL;
// 		return ;
// 	}
// 	cur = find_cmd_by_index(index);
// 	if(!cur)
// 		return;
// 	tmp = cur;
// 	if(cur->prev)
// 	{
// 		(cur->prev)->next = cur->next;
// 		if(cur->next)
// 			(cur->next)->prev = cur->prev;
// 	}
// 	else
// 	{
// 		*v_cmd() = cur->next;
// 		(cur->next)->prev = NULL;
// 	}
// 	ft_free(tmp);
// 	index_the_cmd_list();
// }

void	index_the_cmd_list(void)
{
	int i;
	t_cmd	*cur;

	i = 0;
	cur = *v_cmd();
	if(!cur)
		return ;
	while(cur)
	{
		cur->index = i;
		cur = cur->next;
		i++;
	}
}
