#include "../built_in.h"

void    print_working_directory(void)
{
    char cwd[PATH_MAX];
    if(getcwd(cwd, sizeof(cwd)) != NULL)
        printf("%s\n", cwd);
    else
        perror("getcwd() error\n");
}
