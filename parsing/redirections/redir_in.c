#include "../parsing.h"

bool    if_its_infile(t_cmd *ptr)
{
    if((ptr->type & FILE_NAME)
    && ((ptr->prev && ptr->prev->type & REDIR_IN)))
        return(TRUE);
    return(FALSE);
}

void    open_fd_in(t_cmd *token, int *fd)
{
    if(!token)
        return ;
    if(if_its_infile(token))
    {
        *fd = open(token->content, O_RDONLY, 0666);
        printf("%s\n", token->content);
        if(*fd < 0)
            perror(token->content);
    }
}
