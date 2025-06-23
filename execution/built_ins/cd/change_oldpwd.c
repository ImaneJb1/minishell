#include "../built_in.h"

void	change_oldpwd_var(char *oldpwd)
{
	t_env	*env;

	env = *v_env();
	while (env)
	{
		if (ft_strcmp(env->key, "OLDPWD") == 0)
		{
			env->value = ft_strdup(oldpwd);
			break ;
		}
		env = env->next;
	}
}
