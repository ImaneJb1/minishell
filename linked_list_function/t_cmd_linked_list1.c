/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cmd_linked_list1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:06:29 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/31 17:26:28 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_cmd	*new_cmd_node(char *value)
{
	t_cmd	*elem;

	elem = ft_malloc(sizeof(t_cmd));
	if (!elem)
		return (NULL);
	elem->content = ft_strdup(value);
	elem->prev = NULL;
	elem->next = NULL;
	return (elem);
}

void	lstadd_cmd_back(t_cmd **lst, t_cmd *new)
{
	t_cmd	*last;

	if (!new || !lst)
		return ;
	last = lstlast_cmd();
	if (!last)
		*lst = new;
	else
	{
		last->next = new;
		new->prev = last;
	}
}

void	lstadd_cmd_front(t_cmd **lst, t_cmd *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

t_cmd	*lstlast_cmd(void)
{
	t_cmd *lst;

	lst = *v_cmd();
	if (lst == NULL)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

int	lstsize_cmd(t_cmd *lst)
{
	int		i;
	t_cmd	*tmp;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
