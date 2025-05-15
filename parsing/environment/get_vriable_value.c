/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vriable_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:25:46 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/15 19:47:51 by imeslaki         ###   ########.fr       */
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

char	*field_spliting(t_cmd *cur, char *value)
{
	int i;
	char	*str;

	i = 0;
	while (value[i])
	{
		while (value[i] && !ft_strchr(" \t", value[i]))
			str = join_str_char(str, value[i++]);
		lst_add_one_cmd_by_node();
		skip_space(str, &i);
		i++;
	}
}
char	*expand_the_value(t_cmd *cur, char *command, char *key, int x)
{
	int j;

	j = 0;
	char *value;
	value = get_value_from_env(key);
	if (!value)
		return (command);
	if(x == 0)
		retrun (field_spliting(cur, value));
	while (value[j])
		command = join_str_char(command, value[++j]);
	return (command);
}

// char	*value(char	*key, int *i)
// {
// 	char *value;

// 	while (key[*i] && !ft_strchr("\"\'", key[*i]))
// 	{
// 		value = join_str_char(value, key[*i]);
// 	}
// }



char	*add_var_string(char *command, t_cmd *cur, int *i, int x)
{
	int(j), (flag);
	char (*content), *(key) = NULL;
	t_cmd *cur;
	
	content = cur->content;
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
	if(x == 0 || flag == 1)
		command = expand_the_value(cur, command, key, x);
	else if (content[*i])
		return (join_str_char(command, content[*i]));
	return command;
}
int check(char *content, char *command, int *i, int j)
{
	if (j == 0 && content[*i] == '\'')
	{
		command = inside_quote(command, content, i,'\'');
		return 1;
	}
	else if ((content[*i] == '$' && content[(*i) + 1] == '$'))
	{
		command = ft_strjoin(command, "$$");
		(*i) += 2;
		return 1;
	}
	return 0;
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
		if(check(cur->content, command, &i, j))
			continue;
		else if (is_var_inside_quote(cur->content, i, j))
		{
			command = add_var_string(command, cur, &i, j);
			
		}
		else
			command = join_str_char(command, cur->content[i++]);
	}
	if(!command)
		lst_del_one_cmd_by_node(cur);
	else
		cur->content = command;
}
