/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vriable_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:25:46 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/27 10:21:02 by imeslaki         ###   ########.fr       */
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

char	*expand_the_value(char *command, t_data *data)
{
	int	len;

	data->j = 0;
	data->value = get_value_from_env(data->key);
	if (!data->value)
		return (command);
	len = ft_strlen(command);
	while (data->value[data->j])
	{
		command = join_str_char(command, data->value[data->j]);
		index_the_char(1, len, 0);
		len++;
		data->j++;
	}
	return (command);
}

void	fill_the_key(t_cmd *cur, int *i, t_data *data)
{
	while (cur->content[*i] && (is_valid(cur->content[*i])
			|| (cur->content[*i] == '?' && cur->content[*i - 1] == '$')))
	{
		data->flag = 1;
		if (cur->content[*i - 1] == '$' && (ft_isdigit(cur->content[*i])
				|| cur->content[*i] == '?'))
		{
			data->key = join_str_char(data->key, cur->content[(*i)++]);
			break ;
		}
		data->key = join_str_char(data->key, cur->content[(*i)++]);
		if (!data->key)
			return ;
	}
}

char	*add_var_string(char *command, t_cmd *cur, int *i, int x)
{
	t_data	*data;

	data = init_data();
	(*i)++;
	fill_the_key(cur, i, data);
	data->i = (*i);
	if (x == 0 || data->flag == 1)
		command = expand_the_value(command, data);
	else if (cur->content[*i])
	{
		index_the_char(0, *i, 0);
		return (join_str_char(command, cur->content[*i]));
	}
	return (command);
}
