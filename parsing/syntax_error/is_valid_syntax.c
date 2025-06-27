/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_syntax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:11:50 by ijoubair          #+#    #+#             */
/*   Updated: 2025/06/23 17:14:52 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

static int	check_syntax(t_cmd *ptr)
{
	if (check_pipe_syntax(ptr) < 0)
		return (1);
	if (check_unclosed_quotes(ptr) != 0)
		return (1);
	if (here_doc_error(ptr) < 0)
		return (1);
	if (redir_errors(ptr) < 0)
		return (1);
	if (if_special_at_end(ptr) < 0)
		return (1);
	return (0);
}

bool	is_valid_syntax(void)
{
	t_cmd	*ptr;

	ptr = *v_cmd();
	while (ptr)
	{
		if (check_syntax(ptr))
			return (FALSE);
		ptr = ptr->next;
	}
	return (TRUE);
}
