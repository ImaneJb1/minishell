/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:00:38 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/27 10:27:34 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../parsing.h"

bool	is_dollar_sign(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			if (str[i + 1] && str[i + 1] != ' ')
				return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

void	identify_var(void)
{
	t_cmd	*ptr;

	ptr = *v_cmd();
	while (ptr)
	{
		if (is_dollar_sign(ptr->content))
			ptr->type |= VARIABLE;
		ptr = ptr->next;
	}
}
