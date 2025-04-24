#include "../parsing.h"

int	check_pipe_syntax(void)
{
	t_cmd *ptr;

	ptr = *v_cmd();
	while(ptr)
	{
		if((ptr->type & PIPE) && (!ptr->next || !ptr->prev) )
		{
			print_error("syntax error near unexpected token `|'\n");
			return(-1);
		}
		else if((ptr->type & PIPE) && (ptr->next->type & PIPE))
		{
			print_error("syntax error near unexpected token `|'\n");
			return(-1);
		}
		ptr = ptr->next;
	}
	return(0);
}
