/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vriable_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:25:46 by imeslaki          #+#    #+#             */
/*   Updated: 2025/04/27 17:42:08 by imeslaki         ###   ########.fr       */
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
// key = userilyas value = ilyas
char	*add_var_string(char *command, char *content, int *i, int x)
{
	int(j), (flag);
	char *(key) = NULL;
	j = 0;
	flag = 0;
	(*i)++;
	while (content[*i] && !ft_strchr(" \'\"$><|", content[*i]))
	{
		flag = 1;
		key = join_str_char(key, content[(*i)++]);
		if (!key)
			return (ft_strdup(""));
	}
	if ((x == 0 || flag == 1))
	{
		key = get_value_from_env(key);
		if (!key)
			return (command);
		while (key[j])
			command = join_str_char(command, key[++j]);
		return (command);
	}
	else if (content[*i])
		return (join_str_char(command, content[*i]));
	return (join_str_char(command, '\0'));
}

void	change_var_value(t_cmd *cur)
{
	char *(command), *(key);
	int(i), (j) = 0;
	i = 0;
	key = NULL;
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
		{
			if (!(command = add_var_string(command, cur->content, &i, j)))
				command = ft_strdup("");
		}
		else
			command = join_str_char(command, cur->content[i++]);
	}
	cur->content = ft_strdup(command);
}

void	environment_variable_value(void)
{
	t_cmd	*head;

	head = *v_cmd();
	while (head)
	{
		if (head->type & VARIABLE)
		{
			change_var_value(head);
		}
		head = head->next;
	}
}
