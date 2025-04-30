#include "../parsing.h"

bool	is_special_token(int type)
{
	t_tokens *arr;
	int i;

	arr = init_token_array();
	i = 0;
	while(i < 5)
	{
		if(type & arr[i].type)
			return(TRUE);
		i++;
	}
	return(FALSE);
}
int    if_special_at_end(t_cmd	*ptr)
{
    t_tokens *arr;
    int i;

    i = 0; 
    arr = init_token_array();
    if(ptr && ptr->next == NULL)
    {
        while(i < 5)
        {
            if(arr[i].type & ptr->type)
            {
                print_error("Syntax error near unexpected token \'newline\'\n");
                return(-1);
            }
            i++;
        }
    }    
    return(0);
}

int redir_errors(t_cmd	*ptr)
{
    char *redir[] = {">", "<", ">>", NULL};
    int i;
    
    if(ptr)
    {
        i = 0;
        while(redir[i])
        {
            if(ft_strcmp(ptr->content, redir[i]) == 0)
            {
                if(ptr->next && (!(ptr->next->type & FILE_NAME)))
                {
                    print_error("Syntax error missing filename\n");
                    return(-1);
                }
            }
            i++;
        }
    }
    return(0);

}

bool    if_its_pipe(int type)
{
    if(type & PIPE)
        return(TRUE);
    return(FALSE);
}

int   unexpected_token(t_cmd	*ptr)
{
    if (ptr)
    {
        if(is_special_token(ptr->type))
        {
            if((ptr->type & PIPE) && (ptr->next && (is_special_token(ptr->next->type) && (!if_its_pipe(ptr->next->type)))))
                return(0);
            if(ptr->next && is_special_token(ptr->next->type))
            {
                print_error_with_token("Syntax error near unexpected token ", ptr->next->content);
                return(-1);
            }
        }
    }
    return(0);
}