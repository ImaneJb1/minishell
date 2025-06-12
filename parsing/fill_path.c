#include "parsing.h"

char	*get_env_path(void)
{
	t_env *env;

	env = *v_env();
	while(env)
	{
		if(ft_strcmp(env->key, "PATH") == 0)
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
	if(all_paths == NULL)
		return(NULL);
	i = 0;
	while(all_paths[i])
	{
		tmp = ft_strjoin("/", cmd->cmd);
		path = ft_strjoin(all_paths[i], tmp);
		if(access(path, F_OK | X_OK) == 0)
			return(path);
		i++;
	}
	return(cmd->cmd);
}

void	fill_path(t_exec *cmd)
{
	char *paths;

	paths = get_env_path();
	if(paths == NULL)
	{
		print_cmd_error(cmd->cmd, "no such file or directory");
		cmd->cmd = NULL;
		return;
	}
	if(ft_strchr(cmd->cmd, '/') == NULL)
		paths = find_path(cmd, paths);
	else
		paths = cmd->cmd;
	cmd->path = paths;
}
