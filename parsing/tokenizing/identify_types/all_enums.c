/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_enums.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:27:50 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/27 10:27:51 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../parsing.h"

t_tokens	*init_token_array(void)
{
	static t_tokens	token[] = {
	{"|", PIPE}, {"<", REDIR_IN}, {"<<", HERE_DOC},
	{">", REDIR_OUT}, {">>", APPEND}};

	return (token);
}

void	identify_all_types(void)
{
	if (!v_cmd() || !(*v_cmd()))
		return ;
	identify_symbols();
	identify_delimiter();
	identify_file();
	identify_cmd();
	hanlde_case();
	identify_cmd_arg();
	identify_double_q();
	identify_single_q();
	identify_path();
	identify_var();
	count_heredoc(0);
}
