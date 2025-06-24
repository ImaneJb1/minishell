/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:22:01 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/24 15:24:14 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*unquoted_one_cmd(char *str)
{
	int		i;
	char	*command;
	char	c;

	i = 0;
	c = '\0';
	command = ft_malloc(1);
	while (str[i])
	{
		if (c == 0 && ft_strchr("\"\'", str[i]))
			c = str[i++];
		else if (c == 0 && !ft_strchr("\"\'", str[i]))
			command = join_str_char(command, str[i++]);
		else if (c != 0 && c != str[i])
			command = join_str_char(command, str[i++]);
		else if (c != 0 && c == str[i])
		{
			c = 0;
			i++;
		}
	}
	return (command);
}

char	*unquoted_var_cmd(char *str, int *array)
{
	int		i;
	char	*command;
	char	c;

	i = 0;
	c = '\0';
	command = ft_malloc(1);
	while (str[i])
	{
		if(array && array[i] == 1)
			command = join_str_char(command, str[i++]);
		else if (c == 0 && ft_strchr("\"\'", str[i]))
			c = str[i++];
		else if (c == 0 && !ft_strchr("\"\'", str[i]))
			command = join_str_char(command, str[i++]);
		else if (c != 0 && c != str[i])
			command = join_str_char(command, str[i++]);
		else if (c != 0 && c == str[i])
		{
			c = 0;
			i++;
		}
	}
	return (command);
}

void	remove_quotes(void)
{
	t_cmd	*cmd;

	if (!v_cmd() || !(*v_cmd()))
		return ;
	cmd = *v_cmd();
	while (cmd)
	{
		if ((cmd->type & (DOUBLE_Q | SINGLE_Q)) && !(cmd->type & VARIABLE))
			cmd->content = unquoted_one_cmd(cmd->content);
		else if((cmd->type & (DOUBLE_Q | SINGLE_Q) && (cmd->type & VARIABLE)))
			cmd->content = unquoted_var_cmd(cmd->content, cmd->index);
		cmd = cmd->next;
	}
}
