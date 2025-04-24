/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_checkers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:53:48 by imeslaki          #+#    #+#             */
/*   Updated: 2025/04/24 19:02:57 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

char	*inside_singl_quote(char *command, char *content, int *i)
{
	char	c;

	c = '\0';
	while (content[*i])
	{
		if (content[*i] == '\'' && c == '\0')
		{
			command = join_str_char(command, content[(*i)++]);
			c = command[*i - 1];
		}
		else if (content[*i] == '\'' && c != '\0')
		{
			command = join_str_char(command, content[(*i)++]);
			c = '\0';
		}
		else if (c != '\0')
			command = join_str_char(command, content[(*i)++]);
		else
			break ;
	}
	return (command);
}

int	check_double_quote(char c, int j)
{
	if (j == 0 && c == '\"')
		return (1);
	else if (j == 1 && c != '\"')
		return (1);
	else
		return (0);
}

int is_$_inside_quote(char *c, int i, int j)
{
	if (c[i] == '$' && !ft_strchr(" \'\"$><|", c[i + 1]) && j == 1)
		return (1);
	else if (c[i] == '$' && j == 0)
		return (1);
	return (0);
}
