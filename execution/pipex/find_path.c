#include "../pipex.h"

char	*get_env_path(void)
{
	t_env *env;

	env = v_env();
	while(env)
	{
		if(ft_strcmp(env->key, "PATH"))
			return(env->value);
		env = env->next;
	}
	return(NULL);
}

char	*check_path(t_exec *cmd, char *path)
{
	int i;
	char **all_paths;

	all_paths = ft_split(path, ':');
	i = 0;
	while(all_paths[i])
	{
		if(ft_strchr(cmd->cmd, '/') == NULL)
			path = ft_strjoin()
	}

}