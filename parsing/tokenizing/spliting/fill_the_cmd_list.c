/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_the_cmd_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:55:00 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/16 14:34:17 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../parsing.h"

void	add_to_cmd_list(char ch, int flag)
{
	static char	*str;
	t_cmd		*node;

	if (flag == 0)
		str = NULL;
	else if (flag == 1)
		str = join_str_char(str, ch);
	else if (flag == 2)
	{
		node = new_cmd_node(str);
		lstadd_cmd_back(v_cmd(), node);
	}
}

void	creat_the_cmd_list(char *line)
{
	int			i;
	int			j;
	char		*str;
	static void	(*list[])(char *str, int *i) = {
		is_arg, is_double_quote, is_singl_quote, is_pipe, is_redir_out_append,
		is_heredoc, is_redir_in, is_redir_out, is_var};

	i = 0;
	str = NULL;
	if (!line || !*line)
		return ;
	str = separat_with_one_space(line);
	free(line);
	while (str[i])
	{
		j = 0;
		if (str[i] == ' ' && i++)
			add_to_cmd_list(0, 0);
		while (j < 9)
			list[j++](str, &i);
	}
	identify_all_types();
}
