/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_environment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:16:10 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/27 10:34:11 by imeslaki         ###   ########.fr       */
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

static void	add_to_env_list(char **env, int i)
{
	t_env	*node;
	char	*key;
	char	*value;
	int		j;

	j = 0;
	key = NULL;
	value = NULL;
	key = split_env_key(env[i], &j);
	value = split_env_value(env[i], &j);
	node = new_env_node(key, value);
	node->type = global;
	lstadd_env_back(v_env(), node);
}

void	create_environment(char **env)
{
	int		i;
	t_env	*node;

	i = 0;
	node = new_env_node("?", "0");
	node->type = special;
	lstadd_env_back(v_env(), node);
	while (env[i])
	{
		if (env[i][0] != '?')
			add_to_env_list(env, i);
		i++;
	}
}

void	env(t_exec *node)
{
	t_env	*env;

	if (!node)
		return ;
	env = *v_env();
	if (node->args[1])
	{
		update_exit_status(1);
		return (print_error("too many argument\n"));
	}
	while (env)
	{
		if (env->type == global)
		{
			ft_putstr_fd(env->key, node->fd_out);
			ft_putstr_fd("=", node->fd_out);
			ft_putstr_fd(env->value, node->fd_out);
			ft_putstr_fd("\n", node->fd_out);
		}
		env = env->next;
	}
	update_exit_status(0);
}
