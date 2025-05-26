/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 02:09:47 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/26 14:18:23 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"	
#include "../execution/built_ins/built_in.h"

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

// int	syntax_error(char	*flag)
// {
// 	static int i;

// 	if(flag == NULL)
// 		return i;
// 	if(ft_strcmp("no", flag) == 0)
// 		i = 1;
// 	if(ft_strcmp("yes", flag) == 0)
// 		i = 0;
// 	return i;
// }

// int	is_heredoc_syntax(int flag)
// {
// 	static int i;
	
// 	if(flag == 1)
// 		i = 1;
// 	if(flag == 0)
// 		i = 0;
// 	return i;
// }


int    parsing(char *str)
{
   	creat_the_cmd_list(str);
	if(is_valid_syntax() == FALSE )
        return (ft_free(*v_cmd()), *v_cmd() = NULL, 1);
    expand_variable_value();
	field_spliting();
	print_parsing();
	fill_the_exec_struct();
	lstclear_cmd();
	return 1;
}
