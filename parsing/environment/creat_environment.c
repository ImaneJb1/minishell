/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_environment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:23:22 by imeslaki          #+#    #+#             */
/*   Updated: 2025/04/26 15:15:19 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void	add_to_env(char *key, char *value)
{
	t_env	*node;

	node = new_env_node(key, value);
	lstadd_env_back(v_env(), node);
}

char	*split_env_key(char *line, int *i)
{
	char	*key;

	key = NULL;
	while (line[*i] != '=')
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
	while (line[*i])
	{
		value = join_str_char(value, line[*i]);
		(*i)++;
	}
	return (value);
}

void	creat_environment(char **env)
{
	int		i;
	int		j;
	char	*key;
	char	*value;

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
		add_to_env(key, value);
		i++;
	}
}
