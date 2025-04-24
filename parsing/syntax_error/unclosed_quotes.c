
#include "../parsing.h"

bool	is_unclosed_quotes(char *str, int type)
{
	int	(i), (n);
	char q;

	if(type == SINGLE_Q)
		q = '\'';
	else
		q = '\"';
	n = 0;
	i = 0;
	while (str[i])
	{
		if(str[i] == q)
			n += 1;
		i++;
	}
	if(n < 2)
		return(TRUE);
	return(FALSE);
}

int	check_unclosed_quotes(void)
{
	t_cmd	*ptr;

	ptr = *v_cmd();
	while(ptr)
	{
		if((ptr->type & DOUBLE_Q))
		{
			if(is_unclosed_quotes(ptr->content, DOUBLE_Q))
			{
				print_error("Syntax Error Unclosed Quotes\n");
				return(-1);
			}
		}
		else if((ptr->type & SINGLE_Q))
		{
			if(is_unclosed_quotes(ptr->content, SINGLE_Q))
			{
				print_error("Syntax Error Unclosed Quotes\n");
				return(-1);
			}
		}
		ptr = ptr->next;
	}
	return(0);
}

bool	is_valid_syntax(void)
{
	if(!v_cmd() || !(*v_cmd()))
		return FALSE;
	if(check_pipe_syntax() < 0 || check_unclosed_quotes() < 0  || unexpected_token() < 0 || redir_errors() < 0 || if_special_at_end() < 0)
		return(FALSE);
	return(TRUE);
}
