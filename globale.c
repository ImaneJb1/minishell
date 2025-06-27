/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globale.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 02:10:19 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/27 10:54:43 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	**v_cmd(void)
{
	static t_cmd	*cmd;

	return (&cmd);
}

t_env	**v_env(void)
{
	static t_env	*env;

	return (&env);
}

t_exec	**v_exec(void)
{
	static t_exec	*exec;

	return (&exec);
}

int	**v_array_index(int free_static)
{
	static int	*index;

	if (free_static)
	{
		ft_free(index);
		index = NULL;
	}
	return (&index);
}

int	open_failure(int num)
{
	static int	failure;

	if (num == 0)
		failure = 0;
	if (num == 1)
		failure = 1;
	return (failure);
}
