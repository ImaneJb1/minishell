/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 02:09:47 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/17 17:54:36 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution/built_ins/built_in.h"
#include "parsing.h"

t_data	*init_data(void)
{
	t_data	*data;

	data = ft_malloc(sizeof(t_data));
	data->i = 0;
	data->j = 0;
	data->x = 0;
	data->fd = 0;
	data->count = 0;
	data->pid = 0;
	data->c = 0;
	data->str = NULL;
	data->del = NULL;
	data->key = NULL;
	data->word = NULL;
	data->value = NULL;
	data->content = NULL;
	data->command = NULL;
	data->args = NULL;
	return (data);
}

int	parsing(char *str)
{
	creat_the_cmd_list(str);
	if (is_valid_syntax() == FALSE)
	{
		update_exit_status(2);
		lstclear_cmd();
		return (0);
	}
	expand_variable_value();
	remove_quotes();
	if (!fill_the_exec_struct())
	{
		add_to_exec_list(NULL, NULL, 0);
		lstclear_cmd();
		return (0);
	}
	lstclear_cmd();
	return (1);
}
