/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:03:08 by ijoubair          #+#    #+#             */
/*   Updated: 2025/04/21 02:11:19 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../parsing.h"

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
		ptr->type = WORD;
		while(i < token_len)
		{
			if(ft_strcmp(ptr->content, token[i].input) == 0)
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
				ptr->type = ptr->type | FILE_NAME;											// 	then its a file
		}	
		ptr = ptr->next;
	}
}

// this function handles this case "< file command"
void	hanlde_case(void)
{
	t_cmd *ptr;

	ptr = *v_cmd();
	while(ptr)
	{
		if(ptr->type & FILE_NAME)
		{
			if(ptr->prev && (ptr->prev->type & REDIR_IN))
			{
				if(ptr->next && (ptr->next->type & WORD))
					ptr->next->type |= CMD;
			}
		}
		ptr = ptr->next;
	}	
}
