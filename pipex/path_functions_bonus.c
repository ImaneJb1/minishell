/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_functions_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 12:23:40 by imeslaki          #+#    #+#             */
/*   Updated: 2025/03/11 19:55:01 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*get_absolute_path_bonus(char *arg, t_data *data, char **env)
{
	data->absolute_path = get_path_bonus(arg, data, env);
	if (!data->absolute_path)
	{
		free_all(data);
		errors_bonus(arg, data, data->fdin);
	}
	return (data->absolute_path);
}

char	*get_path_bonus(char *full_cmd, t_data *data, char **env)
{
	data->cmd = ft_split_bonus(full_cmd, ' ');
	if (!data->cmd)
		return (NULL);
	if (*(data->cmd) == NULL)
	{
		free_2d_arry_bonus(data->cmd);
		return (ft_strdup_bonus(""));
	}
	if (data->cmd[0][0] == '/' || data->cmd[0][0] == '.')
	{
		data->exec = ft_strdup_bonus(data->cmd[0]);
		if (access(data->exec, F_OK | X_OK) == 0)
			return (free_2d_arry_bonus(data->cmd), data->exec);
		return (free_2d_arry_bonus(data->cmd), free(data->exec), NULL);
	}
	check_full_paths(full_cmd, data, env);
	data->exec = check_the_absolute_path_bonus(full_cmd, data);
	return (data->exec);
}

void	check_full_paths(char *full_cmd, t_data *data, char **env)
{
	data->full_paths = ft_split_bonus(path_in_env_bonus(env), ':');
	if (!data->full_paths)
	{
		write_in_file(full_cmd, 2);
		write(2, " : command not found\n", 22);
		free(data->exec);
		free_2d_arry_bonus(data->cmd);
		free_all(data);
		exit(127);
	}
}

char	*check_the_absolute_path_bonus(char *full_cmd, t_data *data)
{
	int	i;

	i = -1;
	while (data->full_paths[++i])
	{
		data->cmd_path = ft_strjoin_bonus(data->full_paths[i], "/");
		data->exec = ft_strjoin_bonus(data->cmd_path, data->cmd[0]);
		free(data->cmd_path);
		if (access(data->exec, F_OK | X_OK) == 0)
			return (free_2d_arry_bonus(data->full_paths),
				free_2d_arry_bonus(data->cmd), (data->exec));
		free(data->exec);
	}
	if (data->pipes)
		free_2d_arry_of_integers_bonus(data->pipes, data->number_of_loops);
	if (data->pid)
		free(data->pid);
	free_2d_arry_bonus(data->full_paths);
	free_2d_arry_bonus(data->cmd);
	errors_bonus(full_cmd, data, -1);
	return (NULL);
}

char	*path_in_env_bonus(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp_bonus(env[i], "PATH=", 5) == 0)
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}
