/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:45:08 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/16 14:59:36 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

static int	is_ambiguous__redir_appand(t_cmd *cur)
{
	if ((cur->prev && (cur->prev->type & APPEND)) && !(cur->type & FILE_NAME))
		return (1);
	else if (check_redir(cur, FILE_NAME, APPEND))
	{
		if (field_count_arg(2) > 1)
			return (1);
	}
	return (0);
}

bool	if_its_appfile(t_cmd *ptr)
{
	if (is_ambiguous__redir_appand(ptr))
	{
		is_error(1);
		ft_putstr_fd("bash: ambiguous redirect\n", STDERR_FILENO);
		return (FALSE);
	}
	if (check_redir(ptr, FILE_NAME, APPEND))
		return (TRUE);
	return (FALSE);
}

void	open_fd_app(t_cmd *token, int *fd)
{
	if (if_its_appfile(token))
	{
		*fd = open(token->content, O_RDWR | O_CREAT | O_APPEND, 0666);
		if (*fd < 0)
			perror(token->content);
	}
}
