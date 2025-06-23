/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:51:24 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/17 19:08:57 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

char	*expand_heredoc_string(char *string, char *str, int *i)
{
	t_data	*data;

	data = init_data();
	(*i)++;
	while (str[*i] && is_valid(str[*i]))
		data->key = join_str_char(data->key, str[(*i)++]);
	data->value = get_value_from_env(data->key);
	if (!data->value)
		return (string);
	while (data->value[data->j])
		string = join_str_char(string, data->value[data->j++]);
	return (string);
}

char	*expand_here_doc_value(char *str, int *i)
{
	char	*string;

	string = NULL;
	while (str[*i])
	{
		if ((str[*i] == '$' && str[(*i) + 1] == '$'))
		{
			string = ft_strjoin(string, "$$");
			(*i) += 2;
		}
		else if (str[*i] == '$' && is_valid(str[(*i) + 1]))
			string = expand_heredoc_string(string, str, i);
		else
			string = join_str_char(string, str[(*i)++]);
	}
	return (string);
}

void	check_expand_and_put_in_file(t_data *data, int fd)
{
	data->i = 0;
	while (data->str[data->i])
	{
		if (data->flag == 1)
			data->content = expand_here_doc_value(data->str, &data->i);
		else
			data->content = join_str_char(data->content, data->str[data->i++]);
	}
	if (data->str)
	{
		ft_free(data->str);
		data->str = NULL;
	}
	ft_putstr_fd(join_str_char(data->content, '\n'), fd);
}
