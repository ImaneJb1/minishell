/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_heplers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:52:57 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/16 14:59:20 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

int	is_redirection(t_cmd *cur)
{
	if (cur->type & REDIR_IN)
		return (1);
	if (cur->type & REDIR_OUT)
		return (1);
	if (cur->type & APPEND)
		return (1);
	return (0);
}

int	not_first_cmd(int flag)
{
	static int	i;

	if (flag == 0)
		i = 0;
	else if (flag == 1)
		i = 1;
	return (i);
}

int	check_redir(t_cmd *cur, t_type type1, t_type type2)
{
	if (cur->type & type1)
	{
		if (cur->prev && (cur->prev->type & type2))
			return (1);
	}
	return (0);
}
