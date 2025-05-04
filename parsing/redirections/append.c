#include "../parsing.h"

bool    if_its_apptfile(t_cmd *ptr)
{
    if((ptr->type & APPEND) && (ptr->next && (ptr->next->type & FILE_NAME)))
        return(TRUE);
    return(FALSE);
}

void    open_fd_in(t_cmd *ptr)
{
    while(ptr)
    {
        if(if_its_appfile(ptr))
            return(open(ptr->next->content, O_RDWR | O_CREAT | O_APPEND));
        if(ptr->type & PIPE)
            break;
        ptr = ptr->next;
    }
    return(1);
}
