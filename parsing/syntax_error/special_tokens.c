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

int    if_special_at_end(void)
{
    t_cmd   *ptr;
    t_tokens *arr;
    int i;

    i = 0; 
    arr = init_token_array();
    ptr = *v_cmd();
    while(ptr->next)
        ptr = ptr->next;
    while(i < 5)
    {
        if(arr[i].type & ptr->type)
        {
            print_error("Syntax error near unexpected token \'newline\'\n");
            return(-1);
        }
        i++;
    }
    return(0);
}

int redir_errors(void)
{
    t_cmd *ptr;
    char *redir[] = {">", "<", "<<", ">>", NULL};
    int i;
    
    ptr = *v_cmd();
    while(ptr)
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
        ptr = ptr->next;
    }
    return(0);

}

int   unexpected_token(void)
{
    int i;
    t_cmd *ptr;

    ptr = *v_cmd();
    while (ptr)
    {
        if(is_special_token(ptr->type))
        {
            if(ptr->next && is_special_token(ptr->next->type))
            {
                print_error_with_token("Syntax error near unexpected token ", ptr->next->content);
                return(-1);
            }
        }
        ptr = ptr->next;
    }
    return(0);
}
