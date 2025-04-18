/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:03:08 by ijoubair          #+#    #+#             */
/*   Updated: 2025/04/18 14:53:24 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_tokens *init_token_array(void)
{
	static t_tokens token[] = {{"|", PIPE}, {"<", REDIR_IN}, {"<<", HERE_DOC},
						{">", REDIR_OUT}, {">>", APPEND_REDIRECTION}};
	return(token);
}

// fill symbolls with their types
void	identify_symbols(void)
{
	t_cmd *ptr;
	int i;
	t_tokens *token;
	int token_len;

	token = init_token_array();
	token_len = 5;
	ptr = *v_cmd();
	while(ptr)
	{
		i = 0;
		while(i < token_len)
		{
			ptr->type = WORD;
			if(ft_strcmp(ptr->content, token[i].input))
				ptr->type = token[i].type;
			i++;
		}
		ptr = ptr->next;
	}
}

void	identify_cmd(void)
{
	t_cmd *ptr;

	ptr = *v_cmd();
	if(ptr->type & WORD)
		ptr->type = ptr->type | CMD; // if the first arg is a word then it's CMD
	ptr = ptr->next;
	while(ptr)
	{
		if((ptr->type & WORD) && (ptr->prev->type & PIPE)) // if the previous arg of a word is a PIPE 
			ptr->type = ptr->type | CMD;               // then the word is a CMD
		ptr = ptr->next;
	}
}

void	identify_file(void)
{
	t_cmd *ptr;

	ptr = *v_cmd();
	ptr = ptr->next;
	while(ptr)
	{
		if(ptr->type & WORD)
		{
			if((ptr->prev->type & REDIR_IN) || (ptr->prev->type & REDIR_OUT)) // if the previous arg of a word is a redir in or out
				ptr->type = ptr->type | _FILE;											// 	then its a file
		}	
		ptr = ptr->next;
	}
}
// e_cmd
// e_word
// e_here_doc
// e_red_in
// e_red_out
// e_red_in_app
// e_pip
// e_double_quote
// 
