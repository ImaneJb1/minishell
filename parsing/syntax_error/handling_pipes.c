#include "../parsing.h"

int	check_pipe_syntax(t_cmd *ptr)
{
	if(ptr)
	{
		if((ptr->type & PIPE) && (!ptr->next || !ptr->prev) )
		{
			print_error("syntax error near unexpected token `|'\n");
			return(-1);
		}
		else if((ptr->type & PIPE) && (ptr->next->type & PIPE))
		{
			print_error("pipe near pipe  ");
			return(-1);
		}
	}
	return(0);
}
