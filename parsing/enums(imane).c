/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums(imane).c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:03:08 by ijoubair          #+#    #+#             */
/*   Updated: 2025/04/17 17:11:40 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "./parsing.h"

// t_tokens *init_token_array(void)
// {
// 	static t_tokens token[] = {{"|", PIPE}, {"<", REDIRECTION_IN}, {"<<", HERE_DOC},
// 						{">", REDIRECTION_OUT}, {">>", APPEND_REDIRECTION}};
// 	return(token);
// }

// // fill symbolls with their types
// void	identify_symbols(void)
// {
// 	t_cmd *ptr;
// 	int i;
// 	t_tokens *token;
// 	int token_len;

// 	token = init_token_array();
// 	token_len = sizeof(token) / sizeof(token[0]);
// 	ptr = v_cmd();
// 	ptr->type = CMD;
// 	while(ptr)
// 	{
// 		i = 0;
// 		while(i < token_len)
// 		{
// 			if(ft_strcmp(ptr->content, token[i].input))
// 				ptr->type = token[i].type;
// 			i++;
// 		}
// 		ptr = ptr->next;
// 		if(ptr)
// 			ptr->type = WORD;
// 	}
// }

// // e_cmd
// // e_word
// // e_here_doc
// // e_red_in
// // e_red_out
// // e_red_in_app
// // e_pip
// // e_double_quote
// // 

// void	identify_cmd_file(void)
// {
// 	t_cmd *ptr;

// 	ptr = v_cmd();
// 	while(ptr)
// 	{
// 		if(ptr->type == REDIRECTION_IN || ptr->type == REDIRECTION_OUT)
// 		{
// 			if(ptr->next)
// 				ptr->next->type = FILE;
// 		}
// 		if(ptr->type == PIPE)
// 		{
// 			if(ptr->next)
// 				ptr->next->type = CMD;
// 		}
// 		ptr = ptr->next;
// 	}
// }