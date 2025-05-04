#include "../parsing.h"

bool    if_its_outfile(t_cmd *ptr)
{
    if((ptr->type & REDIR_OUT) && (ptr->next && (ptr->next->type & FILE_NAME)))
        return(TRUE);
    return(FALSE);
}

void    open_fd_in(t_cmd *ptr)
{
    while(ptr)
    {
        if(if_its_outfile(ptr))
            return(open(ptr->next->content, O_RDWR | O_CREAT | O_TRUNC));
        if(ptr->type & PIPE)
            break;
        ptr = ptr->next;
    }
    return(1);
}
