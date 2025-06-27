/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_oldpwd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:36:02 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/27 10:36:02 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built_in.h"

void	change_oldpwd_var(char *oldpwd)
{
	t_env	*env;

	env = *v_env();
	while (env)
	{
		if (ft_strcmp(env->key, "OLDPWD") == 0)
		{
			env->value = ft_strdup(oldpwd);
			break ;
		}
		env = env->next;
	}
}
