/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:11:57 by ijoubair          #+#    #+#             */
/*   Updated: 2025/06/02 15:23:17 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void	print_error_token(char *message, char *token)
{
	print_error(message);
	write(1, "\'", 2);
	print_error(token);
	write(1, "\'", 2);
	write(1, "\n", 2);
}

void	print_error(char *s)
{
	write(2, s, ft_strlen(s));
}

void	print_cmd_error(char *command, char *message)
{
	print_error(command);
	print_error(": ");
	print_error(message);
	print_error("\n");
}
