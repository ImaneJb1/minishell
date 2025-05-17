#include "../built_in.h"

char    *get_pwd(void)
{
    char cwd[PATH_MAX];
        return(getcwd(cwd, sizeof(cwd)));
}

void    change_pwd_var()
{
    char *pwd;
    t_env *node;

    pwd = get_pwd();
    node = is_existe_in_env("PWD");
    node->value = ft_strdup(pwd);
    
}