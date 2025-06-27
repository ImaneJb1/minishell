/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_check_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:02:39 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/27 11:06:05 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built_in.h"

t_env	*is_existe_in_env(char *key)
{
	t_env	*env;

	env = *v_env();
	while (env)
	{
		if (ft_strcmp(env->key, key) == 0)
			return (env);
		env = env->next;
	}
	return (NULL);
}

char	*get_var_value(char *str, int i)
{
	char	*value;

	value = NULL;
	if (str[i] == '=')
		i++;
	else if (str[i] == '+' && str[i + 1] == '=')
		i += 2;
	while (str[i])
		value = join_str_char(value, str[i++]);
	return (value);
}

int	key_is_valid(char c)
{
	static int	flag;

	if (c == '\0' || c == '=' || c == '+')
	{
		flag = 0;
		return (0);
	}
	else if (is_alpha(c))
		return (1);
	else if (c == '_')
	{
		flag = 1;
		return (1);
	}
	else if (ft_isdigit(c) && flag == 1)
		return (1);
	return (0);
}

void	print_export_errors(char *str)
{
	char	*result;

	if (str && *str == '-')
	{
		result = join_str_char(NULL, str[0]);
		result = join_str_char(result, str[1]);
		print_msg_to_fd("minishell: export: ", result, ": invalid option\
		\nexport: usage: export [-fn] [name[=value] ...] or export -p\n",
			2);
		update_exit_status(2);
		ft_free(result);
		return ;
	}
	print_msg_to_fd("Minishell: export: `", str, "': not a valid identifier\n",
		STDERR_FILENO);
	update_exit_status(1);
}

char	*the_key(char *str, int *i)
{
	char	*key;

	key = NULL;
	if (!str || !*str)
		return (NULL);
	while (key_is_valid(str[*i]) || (*i != 0 && isdigit(str[*i])))
	{
		key = join_str_char(key, str[*i]);
		(*i)++;
	}
	if (key && (!str[*i] || str[*i] == '='))
		return (key);
	else if (key && (str[*i] == '+' && str[(*i) + 1] == '='))
		return (key);
	print_export_errors(str);
	return (NULL);
}
