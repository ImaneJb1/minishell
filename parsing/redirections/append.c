#include "../parsing.h"

bool    if_its_appfile(t_cmd *ptr)
{
    if((ptr->type & FILE_NAME) && (ptr->next && (ptr->prev->type & APPEND)))
        return(TRUE);
    return(FALSE);
}

void    open_fd_app(t_cmd *token, int *fd)
{
    if(if_its_appfile(token))
    {
        *fd = open(token->content, O_RDWR | O_CREAT | O_APPEND, 0666);
        if(*fd < 0)
            perror(token->content);
    }
}
