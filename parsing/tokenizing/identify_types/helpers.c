/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:27:41 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/27 10:27:41 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../parsing.h"

bool	is_path(char *str)
{
	if (ft_strchr(str, '/'))
		return (TRUE);
	return (FALSE);
}

bool	is_double_q(char *str)
{
	if (ft_strchr(str, '\"'))
		return (TRUE);
	return (FALSE);
}

bool	is_single_q(char *str)
{
	if (ft_strchr(str, '\''))
		return (TRUE);
	return (FALSE);
}

bool	is_cmd_arg(char *str)
{
	if (ft_strchr(str, '-'))
		return (TRUE);
	return (FALSE);
}
