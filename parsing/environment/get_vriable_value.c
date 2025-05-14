/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vriable_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:25:46 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/13 17:30:49 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

char	*get_value_from_env(char *key)
{
	t_env	*cur_env;

	if (!v_env() || !(*v_env()) || !key)
		return (NULL);
	cur_env = *v_env();
	while (cur_env)
	{
		if (ft_strcmp(cur_env->key, key) == 0)
			return (ft_strdup(cur_env->value));
		cur_env = cur_env->next;
	}
	return (NULL);
}

char	*expand_the_value(char *command, char *key, int j)
{
	key = get_value_from_env(key);
	if (!key)
		return (command);
	while (key[j])
		command = join_str_char(command, key[++j]);
	return (command);
}

char	*add_var_string(char *command, char *content, int *i, int x)
{
	int(j), (flag);
	char *(key) = NULL;
	j = 0;
	flag = 0;
	(*i)++;
	while (content[*i] && (is_valid(content[*i])))
	{
		flag = 1;
		if (content[*i - 1] == '$' && is_digit(content[*i]))
		{
			key = join_str_char(key, content[(*i)++]);
			break;
		}
		key = join_str_char(key, content[(*i)++]);
		if (!key)
			return (ft_strdup(""));
	}
	if ((x == 0 || flag == 1))
		command = expand_the_value(command, key, j);
	else if (content[*i])
		return (join_str_char(command, content[*i]));
	return command;
}

void	change_var_value(t_cmd *cur)
{
	char *(command);
	int(i), (j) = 0;
	i = 0;
	command = NULL;

	while (cur->content[i])
	{
		j = check_double_quote(cur->content[i], j);
		if (j == 0 && cur->content[i] == '\'')
			command = inside_singl_quote(command, cur->content, &i);
		else if ((cur->content[i] == '$' && cur->content[i + 1] == '$'))
		{
			command = ft_strjoin(command, "$$");
			i += 2;
		}
		else if (is_var_inside_quote(cur->content, i, j))
			command = add_var_string(command, cur->content, &i, j);
		else
			command = join_str_char(command, cur->content[i++]);
	}
	if(!command)
		lst_del_one_cmd_by_node(cur);
	else
		cur->content = command;
}
