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
