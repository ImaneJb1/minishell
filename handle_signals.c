/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:08:32 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/12 16:26:23 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing/parsing.h"

void	handle_sig_int(int flag)
{
	flag = inside_child(2);
	if (flag == 0)
	{
		rl_replace_line("", 0);
		write(1, "\n", 1);
		rl_on_new_line();
		rl_redisplay();
		update_exit_status(130);
	}
	else if (flag == 1)
		write(1, "\n", 1);
}

void	sigint_in_heredoc_child(int num)
{
	(void)num;
	ft_exit(130);
}
