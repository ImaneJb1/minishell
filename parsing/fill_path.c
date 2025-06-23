/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:00:38 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/16 15:00:39 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*get_env_path(void)
{
	t_env	*env;

	env = *v_env();
	while (env)
	{
		if (ft_strcmp(env->key, "PATH") == 0)
			return (env->value);
		env = env->next;
	}
	return (NULL);
}

char	*find_path(t_exec *cmd, char *path)
{
	int		i;
	char	**all_paths;
	char	*tmp;

	all_paths = ft_split(path, ':');
	if (all_paths == NULL)
		return (NULL);
	i = 0;
	while (all_paths[i])
	{
		tmp = ft_strjoin("/", cmd->cmd);
		path = ft_strjoin(all_paths[i], tmp);
		if (access(path, F_OK | X_OK) == 0)
			return (path);
		i++;
	}
	return (cmd->cmd);
}

int	is_paht_empty(int flag)
{
	static int	i;

	if (flag == 1)
		i = 1;
	else if (flag == 0)
		i = 0;
	return (i);
}

void	fill_path(t_exec *cmd)
{
	char	*paths;

	paths = get_env_path();
	if (paths == NULL)
		is_paht_empty(1);
	if (ft_strchr(cmd->cmd, '/') == NULL)
	{
		paths = find_path(cmd, paths);
		if (!paths)
			paths = cmd->cmd;
	}
	else
		paths = cmd->cmd;
	cmd->path = paths;
}
