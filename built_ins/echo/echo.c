#include "../built_in.h"

bool    is_dash_n(char *args)
{
    int i;

    i = 1;
    if(args[0] != '-')
        return(FALSE);
    while(args[i] == 'n')
        i++;
    if(args[i] == 0)
        return(TRUE);
    return(FALSE);
}

void    echo(char **args, int fd_out)
{
    int i;
    int flag;

    i = 1;
    flag = 0;
    if(!args[i])
    {
        write(fd_out, "\n", 1);
        return;
    }
    while(args[i])
    {
        if((is_dash_n(args[i]) == FALSE) || (is_dash_n(args[i]) == TRUE && flag == 1))
        {
            write(fd_out, &args[i],ft_strlen(args[i]));
            i++;
            if(args[i]) 
                write(fd_out, " ",1);
            flag = 1;
        }
        i++;
    }
    if(is_dash_n(args[1]) == FALSE)
        write(fd_out, "\n", 1);
}

