#include "../parsing.h"

bool    if_its_apptfile(t_cmd *ptr)
{
    if((ptr->type & APPEND) && (ptr->next && (ptr->next->type & FILE_NAME)))
        return(TRUE);
    return(FALSE);
}

void    open_fd_app(t_cmd *token, int *fd)
{
    if(if_its_appfile(token))
        fd = open(token->next->content, O_RDWR | O_CREAT | O_APPEND);
}
