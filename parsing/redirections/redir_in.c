#include "../parsing.h"

bool    if_its_infile(t_cmd *ptr)
{
    if((ptr->type & REDIR_IN) && (ptr->next && (ptr->next->type & FILE_NAME)))
        return(TRUE);
    return(FALSE);
}

void    open_fd_in(t_cmd *ptr)
{
    while(ptr)
    {
        if(if_its_infile(ptr))
            return(open(ptr->next->content, O_RDONLY));
        if(ptr->type & PIPE)
            break;
        ptr = ptr->next;
    }
    return(0);
}