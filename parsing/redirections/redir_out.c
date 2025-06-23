/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:45:00 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/23 17:26:09 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

static int	is_ambiguous_redir_out(t_cmd *cur)
{
	if ((cur->prev && (cur->prev->type & REDIR_OUT))
		&& !(cur->type & FILE_NAME))
		return (1);
	else if (check_redir(cur, FILE_NAME, REDIR_OUT))
	{
		if (field_count_arg(2) > 1)
			return (1);
	}
	return (0);
}

bool	if_its_outfile(t_cmd *ptr)
{
	if (is_ambiguous_redir_out(ptr))
	{
		is_error(1);
		ft_putstr_fd("bash: ambiguous redirect\n", STDERR_FILENO);
		return (FALSE);
	}
	else if (check_redir(ptr, FILE_NAME, REDIR_OUT))
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
