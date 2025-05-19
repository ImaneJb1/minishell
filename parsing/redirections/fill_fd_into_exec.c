#include "../parsing.h"

void    fill_fds(t_cmd *token, t_exec *node)
{   
    open_fd_in(token, &node->fd_in);
    open_fd_out(token, &node->fd_out);
    open_fd_app(token, &node->fd_out);
}
