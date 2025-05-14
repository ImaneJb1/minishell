#include "../parsing.h"

bool    if_its_infile(t_cmd *ptr)
{
    if((ptr->type & REDIR_IN) && (ptr->next->type & FILE_NAME))
        return(TRUE);
    return(FALSE);
}

void    open_fd_in(t_cmd *token, int *fd)
{
    if(if_its_infile(token))
        fd = open(token->next->content, O_RDONLY);
    return;
}