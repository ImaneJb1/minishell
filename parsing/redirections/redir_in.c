/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imane <imane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:11:00 by ijoubair          #+#    #+#             */
/*   Updated: 2025/06/12 18:41:42 by imane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

bool	if_its_infile(t_cmd *ptr)
{
	if ((ptr->type & FILE_NAME) && ((ptr->prev && ptr->prev->type & REDIR_IN)))
		return (TRUE);
	return (FALSE);
}

void	open_fd_in(t_cmd *token, int *fd)
{
	if (!token)
		return ;
	if (if_its_infile(token))
	{
		*fd = open(token->content, O_RDONLY, 0666);
		if (*fd < 0)
		{
			perror(token->content);
			ft_free_all();
			update_exit_status(1);
		}
	}
}
