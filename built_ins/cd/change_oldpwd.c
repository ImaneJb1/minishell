#include "../built_in.h"

void    change_oldpwd_var(char *oldpwd)
{
    t_env *node;

    node = is_existe_in_env("OLDPWD");
    node->value = ft_strdup(oldpwd);
    
}