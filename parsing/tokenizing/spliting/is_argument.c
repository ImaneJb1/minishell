/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_argument.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 22:35:16 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/13 11:25:48 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../parsing.h"

void	is_arg(char *str, int *i)
{
	if (!ft_strchr(" \"\'|<>$", str[*i]))
	{
		while (str[*i] && !ft_strchr(" |<>", str[*i]))
		{
			if (str[*i] == '\"')
				protect_double_quotes(str, i);
			else if (str[*i] == '\'')
				protect_singl_quotes(str, i);
			else
				add_to_cmd_list(str[(*i)++], 1);
		}
		add_to_cmd_list(0, 2);
		add_to_cmd_list(0, 0);
	}
}
