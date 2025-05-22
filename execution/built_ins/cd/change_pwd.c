#include "../built_in.h"

char    *get_pwd(void)
{
    char cwd[PATH_MAX];
        return(getcwd(cwd, sizeof(cwd)));
}

t_env   *change_node_pwd(char *pwd)
{
    t_env *env;

    env = *v_env();
    while (env)
    {
        if (ft_strcmp(env->key, "PWD") == 0)
        {
            ft_free(env->value);
            env->value = ft_strdup(pwd);
            break;
        }
        env = env->next;
    }
    return NULL;
}

void    change_pwd_var()
{
    char *pwd;

    pwd = get_pwd();
    change_node_pwd(pwd);
}