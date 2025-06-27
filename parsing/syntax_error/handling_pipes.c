/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_pipes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:11:38 by ijoubair          #+#    #+#             */
/*   Updated: 2025/06/02 15:11:45 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

int	check_pipe_syntax(t_cmd *ptr)
{
	if (ptr)
	{
		if ((ptr->type & PIPE) && (!ptr->next || !ptr->prev))
		{
			print_error("syntax error near unexpected token `|'\n");
			return (-1);
		}
		else if ((ptr->type & PIPE) && (ptr->next->type & PIPE))
		{
			print_error("syntax error near unexpected token `|'\n");
			return (-1);
		}
	}
	return (0);
}
