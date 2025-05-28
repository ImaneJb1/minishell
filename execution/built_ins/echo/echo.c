#include "../built_in.h"

bool    is_dash_n(char *args)
{
    int i;

    i = 1;

    if(args && *args != '-')
        return(FALSE);
    while(args[i] == 'n')
        i++;
    if(args[i] == 0)
        return(TRUE);
    return(FALSE);
}


void    echo(t_exec *node)
{
    int i;
    int flag;

    i = 1;
    flag = 0;
    if(!node->args[i])
    {
        write(node->fd_out, "\n", 1);
        return;
    }
    exit_status_case(node->args[1]);
    while(node->args && node->args[i])
    {
        if((is_dash_n(node->args[i]) == FALSE) || (is_dash_n(node->args[i]) == TRUE && flag == 1))
        {
            write(node->fd_out, node->args[i],ft_strlen(node->args[i]));
            if(node->args[i + 1]) 
                write(node->fd_out, " ",1);
            flag = 1;
        }
        i++;
    }
    if(is_dash_n(node->args[1]) == FALSE)
        write(node->fd_out, "\n", 1);
}

