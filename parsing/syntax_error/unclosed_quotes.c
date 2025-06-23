/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unclosed_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:12:05 by ijoubair          #+#    #+#             */
/*   Updated: 2025/06/23 17:15:22 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

int	check_unclosed_quotes(t_cmd *ptr)
{
	int		i;
	char	quote;
	char	*str;

	str = ptr->content;
	quote = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
		{
			if (quote == 0)
				quote = str[i];
			else if (quote == str[i])
				quote = 0;
		}
		i++;
	}
	if (quote != 0)
		print_error("Syntax error unclosed quotes\n");
	return (quote);
}

// int	check_unclosed_quotes(t_cmd	*ptr)
// {
// 	if(ptr)
// 	{
// 		if((ptr->type & DOUBLE_Q))
// 		{
// 			if(is_unclosed_quotes(ptr->content, DOUBLE_Q))
// 			{
// 				print_error("enclosed double quotes ");
// 				return(-1);
// 			}
// 		}
// 		else if((ptr->type & SINGLE_Q))
// 		{
// 			if(is_unclosed_quotes(ptr->content, SINGLE_Q))
// 			{
// 				print_error("enclosed single quotes ");
// 				return(-1);
// 			}
// 		}
// 	}
// 	return(0);
// }

// bool	is_valid_syntax(void)
// {
// 	if(check_pipe_syntax() < 0 || check_unclosed_quotes() < 0 
		// || unexpected_token() < 0 || redir_errors() < 0
		// || if_special_at_end() < 0)
// 	{
// 		return(FALSE);
// 	}
// 	return(TRUE);
// }
