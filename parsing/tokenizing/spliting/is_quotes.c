/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:54:45 by imeslaki          #+#    #+#             */
/*   Updated: 2025/04/21 02:10:35 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../parsing.h"

void	protect_singl_quoat(char *str, int *i, int flag)
{
	while (str[*i])
	{
		if ((str[*i] != '\'' && flag == 0) || (!ft_strchr(" \"\'|<>$", str[*i])
				&& flag == 1))
			add_to_list(str[(*i)++], 1);
		else if (str[*i] == '\'' && !ft_strchr(" |<>$", str[*i + 1]))
		{
			flag = 1;
			add_to_list(str[(*i)++], 1);
		}
		else
		{
			if (str[*i] == '\'' && ft_strchr(" |<>$", str[*i + 1]))
				add_to_list(str[(*i)++], 1);
			break ;
		}
	}
}

void	is_singl_quote(char *str, int *i)
{
	if (str[*i] == '\'')
	{
		add_to_list(str[(*i)++], 1);
		protect_singl_quoat(str, i, 0);
		add_to_list(0, 2);
		add_to_list(0, 0);
	}
}

void	protect_double_quoat(char *str, int *i, int flag)
{
	while (str[*i])
	{
		if ((str[*i] != '\"' && flag == 0) || (!ft_strchr(" \"\'|<>$", str[*i])
				&& flag == 1))
			add_to_list(str[(*i)++], 1);
		else if (str[*i] == '\"' && !ft_strchr(" |<>$", str[*i + 1]))
		{
			flag = 1;
			add_to_list(str[(*i)++], 1);
			;
		}
		else
		{
			if (str[*i] == '\"' && ft_strchr(" |<>$", str[*i + 1]))
				add_to_list(str[(*i)++], 1);
			break ;
		}
	}
}

void	is_double_quote(char *str, int *i)
{
	if (str[*i] == '\"')
	{
		add_to_list(str[(*i)++], 1);
		protect_double_quoat(str, i, 0);
		add_to_list(0, 2);
		add_to_list(0, 0);
	}
}
