#include "../parsing.h"

bool	is_valid_syntax(void)
{
	t_cmd *ptr;

	ptr = *v_cmd();
	while(ptr)
	{
		if(check_pipe_syntax(ptr) < 0 || check_unclosed_quotes(ptr) != 0 
		|| unexpected_token(ptr) < 0 ||	redir_errors(ptr) < 0 || if_special_at_end(ptr) < 0)
			return(FALSE);
		ptr = ptr->next;
	}
	return(TRUE);
}
