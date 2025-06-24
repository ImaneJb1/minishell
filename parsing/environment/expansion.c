/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:31:52 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/23 22:12:10 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

int	check(char *content, t_data **data, int j)
{
	if (j == 0 && content[(*data)->i] == '\'')
	{
		(*data)->command = inside_quote((*data)->command, content, &(*data)->i,
				'\'');
		return (1);
	}
	else if ((content[(*data)->i] == '$' && content[(*data)->i + 1] == '$'))
	{
		(*data)->command = ft_strjoin((*data)->command, "$$");
		index_the_char(0, (*data)->i);
		index_the_char(0, (*data)->i + 1);
		(*data)->i += 2;
		return (1);
	}
	return (0);
}



void	change_var_value(t_cmd *cur)
{
	t_data	*data;

	data = init_data();
	while (cur && cur->content && cur->content[data->i])
	{
		data->flag = check_double_quote(cur->content[data->i], data->flag);
		if (check(cur->content, &data, data->flag))
			continue ;
		else if (is_var_inside_quote(cur->content, data->i, data->flag))
			data->command = add_var_string(data->command, cur, &data->i,
					data->flag);
		else
		{
			index_the_char(0, data->i);
			data->command = join_str_char(data->command, cur->content[data->i++]);
		}
	}
	if (!data->command)
		lst_del_one_cmd(cur);
	else
		cur->content = data->command;
}

void	expand_variable_value(void)
{
	t_cmd	*head;

	head = *v_cmd();
	while (head)
	{
		ft_bzero(*v_array_index(0), ft_strlen(head->content));
		if ((head->type & VARIABLE) && !(head->type & DELIMITER))
		{
			
			change_var_value(head);
		}
		head = head->next;
	}
	field_spliting();
}
