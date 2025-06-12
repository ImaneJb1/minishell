/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vriable_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:25:46 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/12 17:02:18 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

char	*expand_the_value(char *command, t_data *data)
{
	data->j = 0;
	data->value = get_value_from_env(data->key);
	if (!data->value)
		return (command);
	while (data->value[data->j])
		command = join_str_char(command, data->value[data->j++]);
	return (command);
}

void	fill_the_key(t_cmd *cur, int *i, t_data *data)
{
	while (cur->content[*i] && (is_valid(cur->content[*i])
			|| cur->content[*i] == '?'))
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
		return (join_str_char(command, cur->content[*i]));
	return (command);
}

