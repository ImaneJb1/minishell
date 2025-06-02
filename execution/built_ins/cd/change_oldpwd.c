#include "../built_in.h"

void    change_oldpwd_var(char *oldpwd)
{
    t_env *env;

    env = *v_env();
    while (env)
    {
        if (ft_strcmp(env->key, "OLDPWD") == 0)
        {
            // printf("oldpwddddddddddd=%s\n", env->value);
            env->value = ft_strdup(oldpwd);
            // printf("oldp1=%s\n", env->value);
            break;
        }
        env = env->next;
    }
}