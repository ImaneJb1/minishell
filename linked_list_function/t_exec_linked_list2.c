/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_exec_linked_list2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:32:18 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/26 16:01:57 by imeslaki         ###   ########.fr       */
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
		ft_free(cur);
		cur = next;
	}
	*v_exec() = NULL;
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
}

// void	index_the_exec_list(void)
// {
// 	int i;
// 	t_exec	*cur;

// 	i = 0;
// 	cur = *v_exec();
// 	if(!cur)
// 		return ;
// 	while(cur)
// 	{
// 		cur->index = i;
// 		cur = cur->next;
// 		i++;
// 	}
// }
