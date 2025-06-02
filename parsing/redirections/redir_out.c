/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:11:20 by ijoubair          #+#    #+#             */
/*   Updated: 2025/06/02 15:11:21 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

bool	if_its_outfile(t_cmd *ptr)
{
	if ((ptr->type & FILE_NAME) && (ptr->prev && (ptr->prev->type & REDIR_OUT)))
		return (TRUE);
	return (FALSE);
}

void	open_fd_out(t_cmd *token, int *fd)
{
	if (if_its_outfile(token))
	{
		*fd = open(token->content, O_RDWR | O_CREAT | O_TRUNC, 0666);
		if (*fd < 0)
			perror(token->content);
	}
}
