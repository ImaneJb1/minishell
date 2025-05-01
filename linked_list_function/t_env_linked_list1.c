/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_env_linked_list1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:52:33 by imeslaki          #+#    #+#             */
/*   Updated: 2025/04/29 17:24:43 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_env	*new_env_node(char *key, char *value)
{
	t_env	*elem;

	elem = ft_malloc(sizeof(t_env));
	if (!elem)
		return (NULL);
	elem->key = key;
    elem->value = value;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}

void	lstadd_env_back(t_env **lst, t_env *new)
{
	t_env	*last;

	if (!new || !lst)
		return ;
	last = lstlast_env(*lst);
	if (!last)
		*lst = new;
	else
	{
		last->next = new;
		new->prev = last;
	}
}

void	lstadd_env_front(t_env **lst, t_env *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

t_env	*lstlast_env(t_env *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

int	lstsize_env(t_env *lst)
{
	int		i;
	t_env	*tmp;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
