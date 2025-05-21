/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_env_linked_list2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:17:58 by imeslaki          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/05/14 11:26:08 by imeslaki         ###   ########.fr       */
=======
/*   Updated: 2025/05/18 19:10:44 by imeslaki         ###   ########.fr       */
>>>>>>> origin/ilyas
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	lstclear_env(void)
{
	t_env	*cur;
	t_env	*next;

	cur = *v_env();
	if (!cur)
		return ;
	while (cur)
	{
		next = cur->next;
<<<<<<< HEAD
		free(cur->key);
        free(cur->value);
		free(cur);
=======
		ft_free(cur->key);
        ft_free(cur->value);
		ft_free(cur);
>>>>>>> origin/ilyas
		cur = next;
	}
	*v_env() = NULL;
}

t_env	*find_env_by_index(int index)
{
	t_env	*cur;
	cur = *v_env();
	while(cur)
	{
		if(cur->index == index)
			break;	
		cur = cur->next;
	}
	return cur;
}

void	lstadd_one_env_by_node(t_env	*new, t_env	*cur)
{
	if(!cur && cur->prev)
		return;
	else if(!cur->next)
	{
		lstadd_env_back(v_env(), new);
		cur->prev = new;
		new->next = cur;
	}
	else
	{
		new->next = cur;
		new->prev = cur->prev;
		if(!cur->prev)
			*v_env() = new;
		else
			(cur->prev)->next = new;
		cur->prev = new;
	}
	index_the_env_list();
}

void	lst_add_one_env(t_env	*new, int index)
{
	t_env	*cur;

	cur = find_env_by_index(index);
	if(!cur && cur->prev)
		return;
	else if(!cur->next)
	{
		lstadd_env_back(v_env(), new);
		cur->prev = new;
		new->next = cur;
	}
	else
	{
		new->next = cur;
		new->prev = cur->prev;
		if(!cur->prev)
			*v_env() = new;
		else
			(cur->prev)->next = new;
		cur->prev = new;
	}
	index_the_env_list();
}

void	lst_del_one_env_by_node(t_env	*cur)
{
	
	t_env	*tmp;

	if(!*v_env())
		return ;
	if(!(*v_env())->next)
	{
		*v_env() = NULL;
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
		*v_env() = cur->next;
		(cur->next)->prev = NULL;
	}
<<<<<<< HEAD
	free(tmp);
=======
	ft_free(tmp);
>>>>>>> origin/ilyas
	index_the_env_list();
}

void	index_the_env_list(void)
{
	int i;
	t_env	*cur;

	i = 0;
	cur = *v_env();
	if(!cur)
		return ;
	while(cur)
	{
		cur->index = i;
		cur = cur->next;
		i++;
	}
}
