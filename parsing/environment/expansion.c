/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:31:52 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/24 19:01:46 by imeslaki         ###   ########.fr       */
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
		index_the_char(0, (*data)->i, 0);
		index_the_char(0, (*data)->i + 1, 0);
		(*data)->i += 2;
		return (1);
	}
	return (0);
}

void	update_cmd_content(t_cmd	*cur, t_data	*data)
{
	if (!data->command)
	{
		if(!(cur->prev) || (cur->prev && cur->prev->type & PIPE))
		{
			if(cur->next)
				cur->next->type |= CMD;
		}
		lst_del_one_cmd(cur);
	}
	else
	{
		cur->content = data->command;
		cur->index = ft_int_dup(*v_array_index(0), ft_strlen(cur->content));
	}	
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
			index_the_char(0, data->i, 0);
			data->command = join_str_char(data->command, cur->content[data->i++]);
		}
	}
	update_cmd_content(cur, data);
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
			if(*v_array_index(0))
				ft_free(*v_array_index(0));
			index_the_char(0,0,1);
			*v_array_index(0) = NULL;
		}
		head = head->next;
	}
	field_spliting();
}
