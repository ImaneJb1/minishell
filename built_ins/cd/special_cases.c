#include "../built_in.h"

void    cd_home(char *path)
{
    char *home;

    if(ft_strcmp(path, "~") || ft_strcmp(path, ""))
    {
        home = get_value_from_env("HOME");
        if(chdir(home) < 0)
            perror("home error");
    }
}