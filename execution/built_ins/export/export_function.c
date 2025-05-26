/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:46:05 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/24 15:59:31 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built_in.h"

void	appand_var(t_env **node, char *new_value)
{
	char	*appand_value;

	appand_value = NULL;
	if (!new_value)
		(*node)->type = local;
	(*node)->value = ft_strjoin((*node)->value, new_value);
	(*node)->type = global;
}

void	add_var_node(t_env **node, char *new_value)
{
	if (!new_value)
		(*node)->type = local;
	(*node)->value = new_value;
	(*node)->type = global;
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
	if (!is_valid_key(arg, &i))
		return ;
	if (arg[i] == '=' || arg[i] == '+')
		value = get_var_value(arg, i);
	existe = is_existe_in_env(key);
	if (arg[i] == '+' && existe)
		return (appand_var(&existe, value));
	else if (arg[i] == '=' && existe)
		add_var_node(&existe, value);
	existe = new_env_node(key, value);
	if (!value)
		existe->type = local;
	else
		existe->type = global;
	lstadd_env_back(v_env(), existe);
}

void	export(t_exec *node)
{
	int	i;

	i = 0;
	if (!node)
		return ;
	if (ft_strcmp(node->cmd, "export") == 0)
	{
		while (node->args[++i])
			export_arg(node->args[i]);
	}
	else
		return ;
}
