/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:11:00 by ijoubair          #+#    #+#             */
/*   Updated: 2025/06/23 17:06:25 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

// int	infile_index(int flag)
// {
// 	static	int i;

// 	if(flag == 1)
// 		i++;
// 	else if()
// }

// void	function(t_exec	*)
// {
// 	static int i;
// 	open_fd_out(strct->&fd[i]); 
// }

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
			is_error(1);
			update_exit_status(1);
		}
	}
}
