/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_spliting_helpers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:37:10 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/16 14:38:45 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

int	is_not_field(char *content)
{
	int	i;

	i = 0;
	if (ft_strchr(" \t", content[i]))
		return (0);
	while (content[i])
	{
		while (content[i] && !ft_strchr(" \t\'\"", content[i]))
			i++;
		skip_quotes(content, &i);
		if (!content[i])
			return (1);
		if (ft_strchr(" \t", content[i]))
			return (0);
	}
	return (0);
}

int	len_of_word(char *str, int j)
{
	t_data	*data;

	data = init_data();
	while (str[j] && !ft_strchr(" \t", str[j]))
	{
		if (ft_strchr("\"\'", str[j]))
		{
			data->c = str[j++];
			data->count++;
			while (str[j] && str[j] != data->c)
			{
				data->count++;
				j++;
			}
			data->c = 0;
		}
		data->count++;
		j++;
	}
	return (data->count);
}

void	skip_quotes(char *str, int *i)
{
	char	c;

	if (ft_strchr("\'\"", str[*i]))
	{
		c = str[*i];
		(*i)++;
		while (str[*i] && str[*i] != c)
			(*i)++;
		if (str[*i] == c)
			(*i)++;
	}
}

int	field_count_arg(int flag)
{
	static int	i;

	if (flag == 1)
		i += 1;
	else if (flag == 0)
		i = 0;
	else if (flag == -1)
		i -= 1;
	return (i);
}
