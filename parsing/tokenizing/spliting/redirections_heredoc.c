/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_heredoc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:56:33 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/21 10:51:25 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../parsing.h"

void	is_redir_in(char *str, int *i)
{
	if (str[*i] && str[*i] == '<')
	{
		add_to_cmd_list(str[*i], 1);
		(*i)++;
		add_to_cmd_list(0, 2);
		add_to_cmd_list(0, 0);
	}
}

void	is_redir_out(char *str, int *i)
{
	if (str[*i] && str[*i] == '>')
	{
		add_to_cmd_list(str[*i], 1);
		(*i)++;
		add_to_cmd_list(0, 2);
		add_to_cmd_list(0, 0);
	}
}

void	is_redir_out_append(char *str, int *i)
{
	if (str[*i] == '>' && str[*i + 1] == '>')
	{
		add_to_cmd_list(str[*i], 1);
		add_to_cmd_list(str[*i + 1], 1);
		(*i) += 2;
		add_to_cmd_list(0, 2);
		add_to_cmd_list(0, 0);
	}
}

void	is_heredoc(char *str, int *i)
{
	if ( str[*i] == '<' && str[*i + 1] == '<')
	{
		add_to_cmd_list(str[*i], 1);
		add_to_cmd_list(str[*i + 1], 1);
		(*i) += 2;
		add_to_cmd_list(0, 2);
		add_to_cmd_list(0, 0);
	}
}
