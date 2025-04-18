/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_the_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:55:00 by imeslaki          #+#    #+#             */
/*   Updated: 2025/04/18 22:01:01 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void    add_to_list(char ch, int flag)
{
	static char *str;
	t_cmd *node;

	if(flag == 0)
		str = NULL;
	else if(flag == 1)
		str = join_str_char(str, ch);
	else if(flag == 2)
	{
		node = new_node(str);
		lstadd_back(v_cmd(), node);
	}
}

void creat_the_list(char *line)
{
    int i = 0;
	char	*str;

	str = separat_with_one_space(line);
    while(str[i])
    {
		if(str[i] == ' ')
		{
			i++;
			add_to_list(0,0);
		}
		if(is_arg(str, &i))
            ;
		else if(is_double_quote(str, &i))
            ;
        else if(is_singl_quote(str, &i))
            ;
		else if(is_pipe(str, &i))
			;
		else if(is_reder_out_append(str, &i))
			;
		else if(is_heredoc(str, &i))
			;
		else if(is_reder_in(str, &i))
			;
		else if(is_reder_out(str, &i))
			;
		else if(is_var(str, &i))
			;
	}
}



int	is_pipe(char *str, int *i)
{
	if (str[*i] == '|')
	{
        add_to_list(str[*i],1);
		add_to_list(0,2);
		add_to_list(0,0);
		(*i)++;
		return 1;
	}
	return 0;
}

