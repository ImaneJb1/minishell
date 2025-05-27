/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 02:09:47 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/27 18:07:46 by imeslaki         ###   ########.fr       */
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

int	syntax_error(char	*flag)
{
	static int i;

	if(flag == NULL)
		return i;
	if(ft_strcmp("no", flag) == 0)
		i = 0;
	if(ft_strcmp("yes", flag) == 0)
		i = 1;
	return i;
}

// int after_pipe(char	*flag)
// {
// 	static int i;
	
// 	if(flag == NULL)
// 		return i;
// 	if(ft_strcmp("no", flag) == 0)
// 		i = 0;
// 	if(ft_strcmp("yes", flag) == 0)
// 		i = 1;
// 	return i;
// }

int	syntax_error_index(int	flag)
{
	static int i;

	if(flag == 0)
		return i;
	else
		i = flag;
	return i;
}


int    parsing(char *str)
{
   	creat_the_cmd_list(str);
	if(is_valid_syntax() == FALSE)
    	syntax_error("yes");
    expand_variable_value();
	field_spliting();
	print_parsing();
	if(!fill_the_exec_struct())
		return 0;
	lstclear_cmd();
	return 1;
}
