/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_exec_linked_list1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:52:33 by imeslaki          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/05/13 16:10:56 by imeslaki         ###   ########.fr       */
=======
/*   Updated: 2025/05/20 18:32:51 by imeslaki         ###   ########.fr       */
>>>>>>> origin/ilyas
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_exec	*new_exec_node(void)
{
	t_exec	*elem;

	elem = ft_malloc(sizeof(t_exec));
	if (!elem)
		return (NULL);
	elem->cmd = NULL;
    elem->args = NULL;
    elem->fd_in = 0;
    elem->fd_out = 1;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}

void	lstadd_exec_back(t_exec **lst, t_exec *new)
{
	t_exec	*last;

	if (!new || !lst)
		return ;
	last = lstlast_exec();
	if (!last)
		*lst = new;
	else
	{
		last->next = new;
		new->next = NULL;
		new->prev = last;
	}
}

void	lstadd_exec_front(t_exec **lst, t_exec *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

t_exec	*lstlast_exec(void)
{
	t_exec *lst;

	lst = *v_exec();
	if (lst == NULL)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

int	lstsize_exec(void)
{
	int		i;
	t_exec	*tmp;
	t_exec	*lst;

	lst = *v_exec();
	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
