#include "../built_in.h"

void    echo(char **args, int fd_out)
{
    int i;

    i = 0;
    while(args[i])
    {
        write(fd_out, &args[i],ft_strlen(args[i]));
        i++;
        if(args[i]) 
            write(fd_out, " ",1);
    }
}
