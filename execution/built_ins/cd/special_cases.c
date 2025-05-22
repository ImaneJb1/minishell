#include "../built_in.h"

void    cd_home(char *oldpwd)
{
    char *home;
 
    home = get_value_from_env("HOME");
    if(chdir(home) < 0)
        perror("");
    else
    {
        change_pwd_var();
        change_oldpwd_var(oldpwd);
    }
}

void    cd_back(char *oldpwd)
{
    char *prev_wd;

    prev_wd = get_value_from_env("OLDPWD");
    if(chdir(prev_wd) < 0)
        perror("");
    else
    {
        change_pwd_var();
        change_oldpwd_var(oldpwd);
    }
}