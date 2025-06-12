/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:46:05 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/03 14:32:00 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built_in.h"

void	appand_var(t_env **node, char *new_value)
{
	char	*appand_value;

	appand_value = NULL;
	(*node)->type = global;
	(*node)->value = ft_strjoin((*node)->value, new_value);
}

void	add_var_node(t_env **node, char *new_value, char c)
{
	if (!new_value && !ft_strchr("=+", c) && (*node)->type != global)
	{
		(*node)->type = local;
	}
	else
	{
		(*node)->type = global;
	}
	(*node)->value = new_value;
}

void	export_arg(char *arg)
{
	char	*key;
	char	*value;
	t_env	*existe;
	int		i;

	i = 0;
	existe = NULL;
	key = NULL;
	value = NULL;
	key = the_key(arg, &i);
	if (!key)
		return ;
	if (arg[i] == '=' || arg[i] == '+')
		value = get_var_value(arg, i);
	existe = is_existe_in_env(key);
	if (arg[i] == '+' && existe)
		return (appand_var(&existe, value));
	else if (existe)
		return (add_var_node(&existe, value, arg[i]));
	existe = new_env_node(key, value);
	if (!value && !ft_strchr("+=", arg[i]))
		existe->type = local;
	else
		existe->type = global;
	lstadd_env_back(v_env(), existe);
}

void	print_export_var(t_exec *node)
{
	t_env	*env;

	env = *v_env();
	while (env)
	{
		if ((env->type == local) || (env->type == global))
		{
			ft_putstr_fd("declare -x ", node->fd_out);
			ft_putstr_fd(env->key, node->fd_out);
			if (!(!env->value && env->type == local))
			{
				ft_putstr_fd("=", node->fd_out);
				ft_putstr_fd("\"", node->fd_out);
				ft_putstr_fd(env->value, node->fd_out);
				ft_putstr_fd("\"", node->fd_out);
			}
			ft_putstr_fd("\n", node->fd_out);
		}
		env = env->next;
	}
}
void	export(t_exec *node)
{
	int	index;
	int	count;

	if (!node)
		return ;
	index = 1;
	count = strlen_2d_array(node->args);
	if (count == 1)
		print_export_var(node);
	else if (count > 1)
	{
		while (node->args[index])
			export_arg(node->args[index++]);
	}
}
