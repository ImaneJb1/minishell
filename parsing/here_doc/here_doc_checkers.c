/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_checkers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:50:06 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/16 14:42:33 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

int	heredoc_exit_with_signal(int flag)
{
	static int	save_flag;

	if (flag == 1)
		save_flag = 1;
	if (flag == 0)
		save_flag = 0;
	return (save_flag);
}

int	inside_child(int flag)
{
	static int	i;

	if (flag == 1)
		i = 1;
	else if (flag == 0)
		i = 0;
	return (i);
}

int	count_heredoc(int flag)
{
	static int	i;

	if (flag == 1)
		i += flag;
	if (flag == 0)
		i = 0;
	return (i);
}
