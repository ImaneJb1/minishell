/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 02:09:47 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/23 16:02:51 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"	
#include "../built_ins/built_in.h"

t_data	*init_data(void)
{
	t_data *data;

	data = ft_malloc(sizeof(t_data ));
	data->i = 0;
	data->j = 0;
	data->x = 0;
	data->fd = 0;
	data->count = 0;
	data->c = 0;
	data->str = NULL;
	data->del = NULL;
	data->key = NULL;
	data->word = NULL;
	data->value = NULL;
	data->content = NULL;
	data->command = NULL;
	data->args = NULL;
	return data;
}

void	expand_variable_value(void)
{
	t_cmd	*head;

	head = *v_cmd();
	while (head)
	{
		if ((head->type & VARIABLE) && !(head->type & DELIMITER))
			change_var_value(head);
		head = head->next;
	}
	remove_quotes();
}

int    parsing(char *str)
{
   	creat_the_cmd_list(str);
	if(is_valid_syntax() == FALSE)
        return (ft_free(*v_cmd()), *v_cmd() = NULL, 1);
    expand_variable_value();
	field_spliting();
	print_parsing();
	fill_the_exec_struct();
	return 1;
}
