#include "../parsing.h"

int	check_syntax(t_cmd *ptr)
{
	if(check_pipe_syntax(ptr) < 0)
		return 1;
	if(check_unclosed_quotes(ptr) != 0)
		return 1;
	if(here_doc_error(ptr) < 0)
		return 1;
	if(redir_errors(ptr) < 0)
		return 1;
	if(if_special_at_end(ptr) < 0)
		return 1;
	return 0;
}

bool	is_valid_syntax(void)
{
	t_cmd *ptr;

	ptr = *v_cmd();
	while(ptr)
	{
		if(check_pipe_syntax(ptr) < 0 || check_unclosed_quotes(ptr) != 0 
		|| here_doc_error(ptr) < 0 || redir_errors(ptr) < 0 || if_special_at_end(ptr) < 0)
			return(FALSE);
		ptr = ptr->next;
	}
	return(TRUE);
}
