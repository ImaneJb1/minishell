/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_the_cmd_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:55:00 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/13 16:23:56 by imeslaki         ###   ########.fr       */
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
