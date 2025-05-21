/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_pipe_linked_list2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:32:18 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/18 19:11:20 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"


// void	lstclear_cmd(void)
// {
// 	t_pipe	*cur;
// 	t_pipe	*next;

// 	cur = *v_pipe();
// 	if (!cur)
// 		return ;
// 	while (cur)
// 	{
//         next = cur->next;
// 		ft_free(cur->cmd);
//         ft_free(cur->);
// 		ft_free(cur);
//         lstclear_pipe();
// 		cur = next;
// 	}
// 	*v_pipe() = NULL;
// }

t_pipe	*find_pipe_by_index(int index)
{
	t_pipe	*cur;
	cur = *v_pipe();
	while(cur)
	{
		if(cur->index == index)
			break;	
		cur = cur->next;
	}
	return cur;
}

void	lst_add_one_pipe(t_pipe	*new, int index)
{
	t_pipe	*cur;

	cur = find_pipe_by_index(index);
	if(!cur && cur->prev)
		return;
	else if(!cur->next)
	{
		lstadd_pipe_back(v_pipe(), new);
		cur->prev = new;
		new->next = cur;
	}
	else
	{
		new->next = cur;
		new->prev = cur->prev;
		if(!cur->prev)
			*v_pipe() = new;
		else
			(cur->prev)->next = new;
		cur->prev = new;
	}
	index_the_pipe_list();
}

void	lst_del_one_pipe_by_node(t_pipe	*cur)
{
	t_pipe	*tmp;

	if(!*v_pipe())
		return ;
	if(!(*v_pipe())->next)
	{
		*v_pipe() = NULL;
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
		*v_pipe() = cur->next;
		(cur->next)->prev = NULL;
	}
	ft_free(tmp);
	index_the_pipe_list();
}

void	index_the_pipe_list(void)
{
	int i;
	t_pipe	*cur;

	i = 0;
	cur = *v_pipe();
	if(!cur)
		return ;
	while(cur)
	{
		cur->index = i;
		cur = cur->next;
		i++;
	}
}
