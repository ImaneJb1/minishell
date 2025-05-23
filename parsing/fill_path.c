#include "parsing.h"

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

char	*find_path(t_exec *cmd, char *path)
{
	int i;
	char **all_paths;
	char *tmp;

	all_paths = ft_split(path, ':');
	i = 0;
	while(all_paths[i])
	{
		tmp = ft_strjoin("/", cmd->cmd); //tmp = /ls
		path = ft_strjoin(all_paths[i], tmp); //path = /usr/bin/ls
		if(access(path, F_OK | X_OK) == 0)
			return(path);
		i++;
	}
	return(NULL);
}

void	fill_path(t_exec *cmd)
{
	char *paths;

	paths = get_env_path();
	if(ft_strchr(cmd->cmd, '/') == NULL)
		paths = find_path(cmd, paths);
	else
		paths = cmd->cmd;	
	cmd->path = paths;
}
