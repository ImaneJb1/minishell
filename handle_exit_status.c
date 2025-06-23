/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_exit_status.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:16:32 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/23 17:16:12 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_exit_status(int status)
{
	t_env	*env;

	env = *v_env();
	g_exit_status = status;
	while (env)
	{
		if (ft_strcmp(env->key, "?") == 0)
			break ;
		env = env->next;
	}
	env->value = NULL;
	env->value = ft_strdup(ft_itoa(status));
}

void	free_exit(int status)
{
    update_exit_status(status);
	ft_exit(status);
}
