/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_exec_linked_list2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:32:18 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/21 10:36:58 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	lstclear_exec(void)
{
	t_exec	*cur;
	t_exec	*next;

	cur = *v_exec();
	if (!cur)
		return ;
	while (cur)
	{
        next = cur->next;
		if(cur->cmd)
			ft_free(cur->cmd);
		if(cur->args)
		{
        	ft_free(cur->args);
			cur->args = NULL;
		}
			// lstclear_pipe();
		cur = cur->next;
	}
	*v_exec() = NULL;
}

t_exec	*find_exec_by_index(int index)
{
	t_exec	*cur;
	cur = *v_exec();
	while(cur)
	{
		if(cur->index == index)
			break;	
		cur = cur->next;
	}
	return cur;
}

void	lst_add_one_exec(t_exec	*new, int index)
{
	t_exec	*cur;

	cur = find_exec_by_index(index);
	if(!cur && cur->prev)
		return;
	else if(!cur->next)
	{
		lstadd_exec_back(v_exec(), new);
		cur->prev = new;
		new->next = cur;
	}
	else
	{
		new->next = cur;
		new->prev = cur->prev;
		if(!cur->prev)
			*v_exec() = new;
		else
			(cur->prev)->next = new;
		cur->prev = new;
	}
	index_the_exec_list();
}

void	lst_del_one_exec_by_node(t_exec	*cur)
{
	t_exec	*tmp;

	if(!*v_exec())
		return ;
	if(!(*v_exec())->next)
	{
		*v_exec() = NULL;
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
		*v_exec() = cur->next;
		(cur->next)->prev = NULL;
	}
	ft_free(tmp);
	index_the_exec_list();
}

// void	lst_del_one_cmd(int index)
// {
// 	t_exec	*cur;
// 	t_exec	*tmp;

// 	if(!*v_exec())
// 		return ;
// 	if(!(*v_exec())->next)
// 	{
// 		*v_exec() = NULL;
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
// 		*v_exec() = cur->next;
// 		(cur->next)->prev = NULL;
// 	}
// 	ft_free(tmp);
// 	index_the_cmd_list();
// }

void	index_the_exec_list(void)
{
	int i;
	t_exec	*cur;

	i = 0;
	cur = *v_exec();
	if(!cur)
		return ;
	while(cur)
	{
		cur->index = i;
		cur = cur->next;
		i++;
	}
}
