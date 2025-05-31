/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 01:47:02 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/31 11:24:55 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"

void	ft_bzero(void *mem, size_t size)
{
	char	*s;
	size_t	i;

	if (!mem)
		return ;
	s = (char *)mem;
	i = 0;
	while (i < size)
	{
		*s = '\0';
		s++;
		i++;
	}
}

void	*ft_calloc_without_save(size_t n, size_t type_size)
{
	void	*mem;
	size_t	full_size;

	full_size = n * type_size;
	mem = malloc(full_size);
	if (!mem)
	{
		perror("Error memory allocation");
		// ft_exit(1);
		return (NULL);
	}
	ft_bzero(mem, full_size);
	return (mem);
}

void	*ft_calloc(size_t n, size_t type_size)
{
	void	*mem;

	mem = ft_calloc_without_save(n, type_size);
	save_mem(mem);
	return (mem);
}

void	*ft_malloc(size_t n)
{
	return (ft_calloc(1, n));
}

// /////////////////////////////////////////////////////////////////////////////////////////

// t_mem_list	**v_mem_list(void)
// {
// 	static t_mem_list	*list;

// 	return (&list);
// }

// void	*alocalte_mem(size_t	n)
// {
// 	void	*mem;

// 	mem = malloc(n);
// 	if(!mem)
// 	{
// 		perror("Error memory allocation");
// 		ft_free_all();
// 	}
// 	ft_bzero(mem, n);
// }

// t_mem_list	*lstlast_mem(void)
// {
// 	t_mem_list *lst;

// 	lst = *v_mem_list();
// 	if (lst == NULL)
// 		return (NULL);
// 	while (lst->next)
// 	{
// 		lst = lst->next;
// 	}
// 	return (lst);
// }

// void	lstadd_mem_back(t_mem_list *node)
// {
// 	t_mem_list	**list;
// 	t_mem_list	*head;

// 	list = ft_mem_list();
// 	if (!(*list))
// 	{
// 		*list = node;
// 		return ;
// 	}
// 	head = *list;
// 	while (head && head->next)
// 		head = head->next;
// 	head->next = node;
// }

// void	save_mem(void	*mem)
// {
// 	t_mem_list *new;

// 	new = ft_malloc(sizeof(t_mem_list));
// 	new->mem = mem;
// 	lstadd_mem_back(new);
// }
// void	*ft_malloc(size_t	n)
// {
// 	void *mem;

// 	mem = alocalte_mem(n);
// 	save_mem(mem);
// 	return mem;
// }

// void	find_to_free(void *mem)
// {
// 	t_mem_list	*head;
// 	t_mem_list	*prev;

// 	head = (*ft_mem_list());
// 	while (head && head->next)
// 	{
// 		prev = head;
// 		head = head->next;
// 		if (head && head->mem == mem)
// 		{

// 			prev->next = head->next;
// 			free(head->mem);
// 			free(head);
// 			return ;
// 		}
// 	}
// 	free(mem);
// }

// void	ft_free(void *mem)
// {
// 	t_mem_list	**list;
// 	t_mem_list	*cur;

// 	list = v_mem_list();
// 	if (!list || *list || !mem)
// 		return ;
// 	cur = *list;
// 	while (cur)
// 	{
// 		if(cur && cur->mem = mem)
// 	}
	
// }

// void	ft_free_all(void)
// {
// 	t_mem_list	**list;
// 	t_mem_list	*cur;
// 	t_mem_list	*next;

// 	list = v_mem_list();
// 	if (!list || *list)
// 		return ;
// 	cur = *list;
// 	while (cur)
// 	{
// 		next = cur->next;
// 		ft_free(cur->mem);
// 		ft_free(cur);
// 		cur = next;
// 	}
// 	*v_mem_list() = NULL;
// }






