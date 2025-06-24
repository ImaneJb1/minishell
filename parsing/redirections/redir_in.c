/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:11:00 by ijoubair          #+#    #+#             */
/*   Updated: 2025/06/24 16:17:23 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

// void	fill_fdin_arr(t_exec *node)
// {
// 	static int i;

// 	node->fdin_arr[i] = node->fd_in;
// 	print_array(node->fdin_arr);
// 	i++;
// }

static int	is_ambiguous_redir_in(t_cmd *cur)
{
	if ((cur->prev && (cur->prev->type & REDIR_IN)) && !(cur->type & FILE_NAME))
		return (1);
	else if (check_redir(cur, FILE_NAME, REDIR_IN))
	{
		if (field_count_arg(2) > 1)
			return (1);
	}
	return (0);
}

bool	if_its_infile(t_cmd *ptr)
{
	if (is_ambiguous_redir_in(ptr))
	{
		is_error(1);
		ft_putstr_fd("bash: ambiguous redirect\n", STDERR_FILENO);
		return (FALSE);
	}
	if (check_redir(ptr, FILE_NAME, REDIR_IN))
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
			update_exit_status(1);
		}
	}
}
