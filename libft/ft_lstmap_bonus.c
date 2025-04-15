/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 08:00:48 by imeslaki          #+#    #+#             */
/*   Updated: 2024/11/14 23:23:08 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	*f(void *s)
// {
// 	int i = 0;
// 	char *ptr;
// 	char *q = (char *)s;
// 	ptr = malloc(sizeof(char) * ft_strlen(q)+1);
// 	while (q[i])
// 		{
// 			ptr[i] = ft_toupper(q[i]);
// 			i++;
// 		}
// 	return (void *)(ptr);
// }

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*tmp;
	void	*cont;

	if (!lst || !f || !del)
		return (NULL);
	newlst = NULL;
	while (lst)
	{
		cont = f(lst->content);
		tmp = ft_lstnew(cont);
		if (!tmp)
		{
			del(cont);
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, tmp);
		lst = lst->next;
	}
	return (newlst);
}

// int main ()
// {
// 	t_list *head = NULL;
// 	t_list *node1 = ft_lstnew("a");
// 	t_list *node2 = ft_lstnew("b");
// 	t_list *node3 = ft_lstnew("c");
// 	t_list *headd = NULL;
// 	ft_lstadd_back(&head,node1);
// 	ft_lstadd_back(&head,node2);
// 	ft_lstadd_back(&head,node3);
// 	t_list *new = ft_lstmap(head,f,free);
// 	headd = new;
// 	while(headd)
// 	{
// 		printf("%s\n",(char *)headd->content);
// 		headd = headd->next;
// 	}
// }