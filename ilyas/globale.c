#include "parsing.h"

t_cmd   *v_cmd(void)
{
    static t_cmd cmd;

    return &cmd;
}

t_pipe  *pipe(void)
{
    static  t_pipe pip;

    return &pip;
}