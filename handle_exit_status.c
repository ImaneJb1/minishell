#include "minishell.h"

void    update_exit_status(int status)
{
    t_env   *env;

    env = *v_env();
    while (env)
    {
        if(ft_strcmp(env->key, "?") == 0)
            break;
        env = env->next;
    }
    // ft_free(env->value);
    env->value = NULL;
    env->value = ft_strdup(ft_itoa(status));
}

void	free_exit(int status)
{
	update_exit_status(status);
	ft_exit(status);
}
