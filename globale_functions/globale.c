#include "parsing.h"

t_cmd   **v_cmd(void)
{
    static t_cmd *cmd;

    return &cmd;
}

t_pipe  *v_pipe(void)
{
    static  t_pipe pipe;

    return &pipe;
}