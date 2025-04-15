/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 01:24:55 by imeslaki          #+#    #+#             */
/*   Updated: 2025/03/08 03:02:57 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_the_absolute_path(char *arg, t_data *data, char **env)
{
	data->absolute_path = get_path(arg, data, env);
	if (!data->absolute_path)
		errors(arg, data, data->fdin);
	return (data->absolute_path);
}

char	*get_path(char *full_cmd, t_data *data, char **env)
{
	data->cmd = ft_split(full_cmd, ' ');
	if (!data->cmd)
		return (NULL);
	if (*(data->cmd) == NULL)
	{
		free_2d_arry(data->cmd);
		return (ft_strdup(""));
	}
	if (data->cmd[0][0] == '/' || data->cmd[0][0] == '.')
	{
		data->exec = ft_strdup(data->cmd[0]);
		if (access(data->exec, F_OK | X_OK) == 0)
			return (free_2d_arry(data->cmd), data->exec);
		free_2d_arry(data->cmd);
		free(data->exec);
		return (NULL);
	}
	check_full_paths(full_cmd, data, env);
	data->exec = check_the_absolute_path(full_cmd, data);
	return (data->exec);
}

void	check_full_paths(char *full_cmd, t_data *data, char **env)
{
	data->full_paths = ft_split(path_in_env(env), ':');
	if (!data->full_paths)
	{
		put_str(full_cmd, 2);
		free(data->exec);
		free_2d_arry(data->cmd);
		free(data->absolute_path);
		write(2, " : command not found\n", 22);
		exit(127);
	}
}

char	*check_the_absolute_path(char *full_cmd, t_data *data)
{
	int	i;

	i = -1;
	while (data->full_paths[++i])
	{
		data->cmd_path = ft_strjoin(data->full_paths[i], "/");
		data->exec = ft_strjoin(data->cmd_path, data->cmd[0]);
		free(data->cmd_path);
		if (access(data->exec, F_OK | X_OK) == 0)
			return (free_2d_arry(data->full_paths), free_2d_arry(data->cmd),
				(data->exec));
		free(data->exec);
	}
	free_2d_arry(data->full_paths);
	free_2d_arry(data->cmd);
	errors(full_cmd, data, -1);
	return (NULL);
}

char	*path_in_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}
