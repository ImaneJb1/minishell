/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:54:45 by imeslaki          #+#    #+#             */
/*   Updated: 2025/04/24 16:12:26 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../parsing.h"

void	protect_singl_quoat(char *str, int *i)
{
	char	c;

	c = '\0';
	while (str[*i])
	{
		if (str[*i] == '\'' && c == '\0')
		{
			c = str[(*i)];
			add_to_list(str[(*i)++], 1);
		}
		else if (str[*i] == '\'' && c != '\0')
		{
			c = '\0';
			add_to_list(str[(*i)++], 1);
		}
		else if (c != '\0')
			add_to_list(str[(*i)++], 1);
		else if (c == '\0' && !ft_strchr(" \"\'|<>", str[*i]))
			add_to_list(str[(*i)++], 1);
		else if (c == '\0' && ft_strchr(" \"\'|<>", str[*i]))
			break;
	}
}

void	is_singl_quote(char *str, int *i)
{
	if (str[*i] == '\'')
	{
		protect_singl_quoat(str, i);
		add_to_list(0, 2);
		add_to_list(0, 0);
	}
}

void	protect_double_quoat(char *str, int *i)
{
// 		there is a problem not fixed (infinite loop)
	char	c;

	c = '\0';
	while (str[*i])
	{
		if (str[*i] == '\"' && c == '\0')
		{
			c = str[(*i)];
			add_to_list(str[(*i)++], 1);
		}
		else if (str[*i] == '\"' && c != '\0')
		{
			c = '\0';
			add_to_list(str[(*i)++], 1);
		}
		else if (c != '\0')
			add_to_list(str[(*i)++], 1);
		else if (c == '\0' && !ft_strchr(" \"\'|<>", str[*i]))
			add_to_list(str[(*i)++], 1);
		else if (c == '\0' && ft_strchr(" \"\'|<>", str[*i]))
			break;
	}
}

void	is_double_quote(char *str, int *i)
{
	if (str[*i] == '\"')
	{
		protect_double_quoat(str, i);
		add_to_list(0, 2);
		add_to_list(0, 0);
	}
}

// void	protect_double_quoat(char *str, int *i, int flag)
// {
// 	char c;

// 	c = '\0';
// 	while (str[*i])
// 	{
// 		if(str[*i] == '\"' || str[*i] == '\'')
// 			c = str[*i];
// 		if ((str[*i] != '\"' && flag == 0) || (!ft_strchr(" \"\'|<>$", str[*i])
// 				&& c != '\0'))
// 			add_to_list(str[(*i)++], 1);
// 		else if (str[*i] == '\"' && !ft_strchr(" |<>$", str[*i + 1]))
// 		{
// 			flag = 1;
// 			add_to_list(str[(*i)++], 1);
// 		}
// 		else
// 		{
// 			if (str[*i] == '\"' && ft_strchr(" |<>$", str[*i + 1]))
// 				add_to_list(str[(*i)++], 1);
// 			break ;
// 		}
// 	}
// }