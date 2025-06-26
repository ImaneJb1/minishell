/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:11:57 by ijoubair          #+#    #+#             */
/*   Updated: 2025/06/26 15:48:27 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void	print_error_token(char *message, char *token)
{
	write(2, "minishell: ", 11);
	write(2, message, ft_strlen(message));
	write(2, "\'", 1);
	write(2, token, ft_strlen(token));
	write(2, "\'", 1);
	write(2, "\n", 1);
}

void	print_error(char *s)
{
	write(2, "minishell: ", 11);
	if(s)
		write(2, s, ft_strlen(s));
}

void	print_cmd_error(char *command, char *message)
{	
	write(2, "minishell: ", 11);
	write(2, command, ft_strlen(command));
	write(2, ":", 1);
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
}
