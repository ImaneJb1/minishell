/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vriable_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:25:46 by imeslaki          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/05/13 17:30:49 by imeslaki         ###   ########.fr       */
=======
/*   Updated: 2025/05/18 17:35:13 by imeslaki         ###   ########.fr       */
>>>>>>> origin/ilyas
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

<<<<<<< HEAD
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
=======
char	*expand_the_value(t_cmd *cur, char *command, t_data *data, int x)
{
	char	*save;

	save = NULL;
	data->j = 0;
	data->value = get_value_from_env(data->key);
	if (!data->value)
		return (command);
	while (data->value[data->j])
		command = join_str_char(command, data->value[data->j++]);
	return (command);
}

char	*add_var_string(char *command, t_cmd *cur, int *i, int x)
{
	t_data *data;

	data = init_data();
	(*i)++;
	while (cur->content[*i] && (is_valid(cur->content[*i])))
	{
		data->flag = 1;
		if (cur->content[*i - 1] == '$' && is_digit(cur->content[*i]))
		{
			data->key = join_str_char(data->key, cur->content[(*i)++]);
			break;
		}
		data->key = join_str_char(data->key, cur->content[(*i)++]);
		if (!data->key)
			return (ft_strdup(""));
	}
	data->i = (*i);
	if(x == 0 || data->flag == 1)
		command = expand_the_value(cur, command, data, x);
	else if (cur->content[*i])
		return (join_str_char(command, cur->content[*i]));
	return command;
}
int check(char *content, t_data **data, int j)
{
	if (j == 0 && content[(*data)->i] == '\'')
	{
		(*data)->command = inside_quote((*data)->command, content, &(*data)->i,'\'');
		return 1;
	}
	else if ((content[(*data)->i] == '$' && content[(*data)->i + 1] == '$'))
	{
		(*data)->command = ft_strjoin((*data)->command, "$$");
		(*data)->i += 2;
		return 1;
	}
	return 0;
}
void	change_var_value(t_cmd *cur)
{
	t_data *data;

	data = init_data();
	while (cur && cur->content && cur->content[data->i])
	{
		data->flag = check_double_quote(cur->content[data->i], data->flag);
		if(check(cur->content, &data, data->flag))
			continue;
		else if (is_var_inside_quote(cur->content, data->i, data->flag))
			data->command = add_var_string(data->command, cur, &data->i, data->flag);
		else
			data->command = join_str_char(data->command, cur->content[data->i++]);
	}
	if(!data->command)
		lst_del_one_cmd_by_node(cur);
	else
		cur->content = data->command;
>>>>>>> origin/ilyas
}
