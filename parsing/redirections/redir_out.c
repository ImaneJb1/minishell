#include "../parsing.h"

bool    if_its_outfile(t_cmd *ptr)
{
    if((ptr->type & FILE_NAME) && (ptr->prev && (ptr->prev->type & REDIR_OUT)))
        return(TRUE);
    return(FALSE);
}

void    open_fd_out(t_cmd *token, int *fd)
{
    if(if_its_outfile(token))
        *fd = open(token->content, O_RDWR | O_CREAT | O_TRUNC, 0666);
    if(*fd < 0)
        perror(token->content);
}
