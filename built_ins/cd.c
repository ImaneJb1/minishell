#include "built_in.h"

void    change_directory(char *path)
{
    if(chdir(path) < 0)
        perror("chdir error\n");
}