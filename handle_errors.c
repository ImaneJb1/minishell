/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:07:27 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/27 11:03:55 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing/parsing.h"

void	print_msg_to_fd(char *s1, char *s2, char *s3, int fd)
{
	if (s1)
		ft_putstr_fd(s1, fd);
	if (s2)
		ft_putstr_fd(s2, fd);
	if (s3)
		ft_putstr_fd(s3, fd);
}

void	print_proc_error(char *s1, char *s2, char *s3, int fd)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	result = ft_strjoin(result, s3);
	write(fd, result, ft_strlen(result));
}

void	file_errors(t_exec *cmd)
{
	if (open(cmd->cmd, O_RDWR) && !ft_strchr(cmd->cmd, '/'))
	{
		print_proc_error("minishell: ", cmd->cmd, ": command not found\n",
			2);
		ft_exit(127);
	}
	print_proc_error("minishell: ", cmd->cmd, ": Permission denied\n", 2);
	ft_exit(126);
}

void	print_execve_errors(t_exec *cmd)
{
	if (errno == EACCES)
		file_errors(cmd);
	else if (errno == ENOENT)
	{
		if (ft_strchr(cmd->cmd, '/') || is_path_empty(2))
			print_proc_error("minishell: ", cmd->cmd,
				": No such file or directory\n", 2);
		else
			print_proc_error("minishell: ", cmd->cmd, ": command not found\n",
				2);
		ft_exit(127);
	}
	else
	{
		perror("minishell: ");
		ft_exit(1);
	}
}
