#include "../built_in.h"

void    echo(char **args, int fd_out)
{
    int i;

    i = 0;
<<<<<<< HEAD
    if(!args)
    {
        write(fd_out, "\n", 1);
        return;
    }
=======
>>>>>>> origin/ilyas
    while(args[i])
    {
        write(fd_out, &args[i],ft_strlen(args[i]));
        i++;
<<<<<<< HEAD
        if(args[i]) 
            write(fd_out, " ",1);
    }
    if(ft_strcmp(args[0], "-n") != 0)
        write(fd_out, "\n", 1);
=======
    }
>>>>>>> origin/ilyas
}
