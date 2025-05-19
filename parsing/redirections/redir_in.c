#include "../parsing.h"

bool    if_its_infile(t_cmd *ptr)
{
    if((ptr->type && (ptr->type & FILE_NAME)) 
    && ((ptr->prev && ptr->prev->type & REDIR_IN)))
        return(TRUE);
    return(FALSE);
}

void    open_fd_in(t_cmd *token, int *fd)
{
    if(if_its_infile(token->prev))
        *fd = open(token->prev->content, O_RDONLY);
    if(*fd < 0)
        perror(token->content);
}
