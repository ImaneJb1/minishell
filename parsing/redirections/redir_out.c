#include "../parsing.h"

bool    if_its_outfile(t_cmd *ptr)
{
    if((ptr->type & REDIR_OUT) && (ptr->next && (ptr->next->type & FILE_NAME)))
        return(TRUE);
    return(FALSE);
}

void    open_fd_out(t_cmd *token, int *fd)
{
    if(if_its_outfile(token))
        fd = open(token->next->content, O_RDWR | O_CREAT | O_TRUNC);
}
