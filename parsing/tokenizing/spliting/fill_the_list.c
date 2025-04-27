/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_the_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:55:00 by imeslaki          #+#    #+#             */
/*   Updated: 2025/04/22 18:10:15 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../parsing.h"

void	add_to_list(char ch, int flag)
{
	static char	*str;
	t_cmd		*node;

	if (flag == 0)
		str = NULL;
	else if (flag == 1)
		str = join_str_char(str, ch);
	else if (flag == 2)
	{
		node = lst_new_cmd_node(str);
		lstadd_cmd_back(v_cmd(), node);
	}
}

void	creat_the_list(char *line)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	if(!line)
		return;
	str = separat_with_one_space(line);
	while (str[i])
	{
		if (str[i] == ' ' && i++)
			add_to_list(0, 0);
		is_arg(str, &i);
		is_double_quote(str, &i);
		is_singl_quote(str, &i);
		is_pipe(str, &i);
		is_redir_out_append(str, &i);
		is_heredoc(str, &i);
		is_redir_in(str, &i);
		is_redir_out(str, &i);
		is_var(str, &i);
	}
	index_the_cmd_list();
}
