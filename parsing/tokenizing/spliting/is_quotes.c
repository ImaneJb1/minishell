/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:54:45 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/16 14:29:27 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../parsing.h"

static void	assigning_char_and_add_to_list(char *c, char ch, char *str, int *i)
{
	*c = ch;
	add_to_cmd_list(str[(*i)++], 1);
}

void	protect_singl_quotes(char *str, int *i)
{
	char	c;

	c = '\0';
	while (str[*i])
	{
		if (str[*i] == '\'' && c == '\0')
			assigning_char_and_add_to_list(&c, str[(*i)], str, i);
		else if (str[*i] == '\'' && c != '\0')
			assigning_char_and_add_to_list(&c, '\0', str, i);
		else if (c != '\0')
			add_to_cmd_list(str[(*i)++], 1);
		else if (c == '\0' && !ft_strchr(" \"\'|<>", str[*i]))
			add_to_cmd_list(str[(*i)++], 1);
		else if (c == '\0' && ft_strchr(" \"\'|<>", str[*i]))
		{
			if (str[*i] == '\"')
				protect_double_quotes(str, i);
			else
				break ;
		}
	}
}

void	is_singl_quote(char *str, int *i)
{
	if (str[*i] == '\'')
	{
		protect_singl_quotes(str, i);
		add_to_cmd_list(0, 2);
		add_to_cmd_list(0, 0);
	}
}

void	protect_double_quotes(char *str, int *i)
{
	char	c;

	c = '\0';
	while (str[*i])
	{
		if (str[*i] == '\"' && c == '\0')
			assigning_char_and_add_to_list(&c, str[(*i)], str, i);
		else if (str[*i] == '\"' && c != '\0')
			assigning_char_and_add_to_list(&c, '\0', str, i);
		else if (c != '\0')
			add_to_cmd_list(str[(*i)++], 1);
		else if (c == '\0' && !ft_strchr(" \"\'|<>", str[*i]))
			add_to_cmd_list(str[(*i)++], 1);
		else if (c == '\0' && ft_strchr(" \"\'|<>", str[*i]))
		{
			if (str[*i] == '\'')
				protect_singl_quotes(str, i);
			else
				break ;
		}
	}
}

void	is_double_quote(char *str, int *i)
{
	if (str[*i] == '\"')
	{
		protect_double_quotes(str, i);
		add_to_cmd_list(0, 2);
		add_to_cmd_list(0, 0);
	}
}
