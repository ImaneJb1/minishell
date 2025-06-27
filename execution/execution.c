/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:37:25 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/27 10:37:26 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	main_execution(void)
{
	t_exec	*cmd;
	int		length;

	length = lstsize_exec();
	cmd = *v_exec();
	if (!cmd)
		return ;
	if (length == 1)
	{
		execute_simple_cmd(cmd);
		open_failure(0);
	}
	else
	{
		open_failure(0);
		pipes();
	}
}
