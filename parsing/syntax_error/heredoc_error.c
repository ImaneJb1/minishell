/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:11:46 by ijoubair          #+#    #+#             */
/*   Updated: 2025/06/23 17:14:20 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

t_tokens	*init_redir_array(void)
{
	static t_tokens	token[] = {
	{"<", REDIR_IN}, {"<<", HERE_DOC}, {">", REDIR_OUT}, {">>", APPEND}};

	return (token);
}

int	here_doc_error(t_cmd *ptr)
{
	if (ptr)
	{
		if ((ptr->type & HERE_DOC) && (ptr->next
				&& !(ptr->next->type & DELIMITER)))
		{
			print_error_token("Syntax error near unexpected token ",
				ptr->next->content);
			return (-1);
		}
	}
	return (0);
}
