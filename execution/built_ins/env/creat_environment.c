/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_environment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:23:22 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/27 17:25:02 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built_in.h"

char	*split_env_key(char *line, int *i)
{
	char	*key;

	key = NULL;
	while (line[*i] && line[*i] != '=')
	{
		key = join_str_char(key, line[*i]);
		(*i)++;
	}
	return (key);
}

char	*split_env_value(char *line, int *i)
{
	char	*value;

	value = NULL;
	(*i)++;
	while (line[*i])
	{
		value = join_str_char(value, line[*i]);
		(*i)++;
	}
	return (value);
}

void	create_environment(char **env)
{
	int		i;
	int		j;
	char	*key;
	char	*value;
	t_env	*node;

	i = 0;
	key = NULL;
	value = NULL;
	if (!env || !(*env))
		return ;
	while (env[i])
	{
		j = 0;
		key = split_env_key(env[i], &j);
		value = split_env_value(env[i], &j);
		node = new_env_node(key, value);
		node->type = global;
		lstadd_env_back(v_env(), node);
		i++;
	}
	node = new_env_node("?", "0");
	node->type = special;
	lstadd_env_back(v_env(), node);
}

void	env(t_exec	*node)
{
	t_env	*env;

	if(!node)
		return ;
	// if(lstsize_exec() > 1)
	// {
	// 	is_error(1);
	// 	return ;
	// }
	env = *v_env();
	while(env)
	{
		if(env->type == global)
		{
			ft_putstr_fd(env->key, node->fd_out);
			ft_putstr_fd("=", node->fd_out);
			ft_putstr_fd(env->value, node->fd_out);
			ft_putstr_fd("\n", node->fd_out);
		}
		env = env->next;
	}
}
