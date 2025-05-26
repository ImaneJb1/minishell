/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_pipe_linked_list1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:52:33 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/26 14:19:55 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_pipe	*new_pipe_node( int read, int write)
{
	t_pipe	*elem;

	elem = ft_malloc(sizeof(t_pipe));
	if (!elem)
		return (NULL);
    if(read != -2)
        elem->read = read;
    if(write != -2)
    	elem->write = write;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}

void	lstadd_pipe_back(t_pipe **lst, t_pipe *new)
{
	t_pipe	*last;

	if (!new || !lst)
		return ;
	last = lstlast_pipe(*lst);
	if (!last)
		*lst = new;
	else
	{
		last->next = new;
		new->prev = last;
	}
}

void	lstadd_pipe_front(t_pipe **lst, t_pipe *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

t_pipe	*lstlast_pipe(t_pipe *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

// int	lstsize_pipe(t_pipe *lst)
// {
// 	int		i;
// 	t_pipe	*tmp;

// 	tmp = lst;
// 	i = 0;
// 	while (tmp)
// 	{
// 		tmp = tmp->next;
// 		i++;
// 	}
// 	return (i);
// }
