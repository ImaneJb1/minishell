/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_exec_linked_list2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:32:18 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/16 15:22:04 by imeslaki         ###   ########.fr       */
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
		if (cur->cmd)
			ft_free(cur->cmd);
		if (cur->args)
		{
			ft_free(cur->args);
			cur->args = NULL;
		}
		ft_free(cur);
		cur = next;
	}
	*v_exec() = NULL;
}
