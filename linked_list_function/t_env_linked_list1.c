/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_env_linked_list1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:52:33 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/16 15:21:53 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_env	*new_env_node(char *key, char *value)
{
	t_env	*elem;

	elem = ft_malloc(sizeof(t_env));
	if (!elem)
		return (NULL);
	elem->key = ft_strdup(key);
	elem->value = ft_strdup(value);
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}

void	lstadd_env_back(t_env **lst, t_env *new)
{
	t_env	*last;

	if (!new || !lst)
		return ;
	last = lstlast_env();
	if (!last)
		*lst = new;
	else
	{
		last->next = new;
		new->prev = last;
	}
}

t_env	*lstlast_env(void)
{
	t_env	*lst;

	lst = *v_env();
	if (lst == NULL)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

int	lstsize_env(void)
{
	int		i;
	t_env	*tmp;
	t_env	*lst;

	lst = *v_env();
	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
