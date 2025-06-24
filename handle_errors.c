/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:07:27 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/24 16:24:00 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing/parsing.h"

int	is_error(int flag)
{
	static int	i;

	if (flag == 0)
		i = 0;
	else if (flag == 1)
		i = 1;
	return (i);
}

int	handle_exec_error(void)
{
	not_first_cmd(0);
	is_error(0);
	field_count_arg(0);
	return (0);
}

void	print_msg_to_fd(char *s1, char *s2, char *s3, int fd)
{
	ft_putstr_fd(s1, fd);
	ft_putstr_fd(s2, fd);
	ft_putstr_fd(s3, fd);
}

int	fd_error(t_exec *cmd)
{
	if (cmd->fd_in < 0)
		return (1);
	if (cmd->fd_out < 0)
		return (1);
	return (0);
}

void	print_proc_error(char *s1, char *s2, char *s3, int fd)
{
	char *result;

	(void)fd;
	result = ft_strjoin(s1, s2);
	result = ft_strjoin(result, s3);
	write(fd, result, ft_strlen(result));
}

void	print_execve_errors(t_exec *cmd)
{
	if (errno == EACCES)
		print_proc_error("minishell: ", cmd->cmd, ": Permission denied\n", 2);
	else if (errno == ENOENT)
	{
		if (ft_strchr(cmd->cmd, '/') || is_path_empty(0))
			print_proc_error("minishell: ", cmd->cmd, ": No such file or directory\n", 2);
		else
			print_proc_error("minishell: ", cmd->cmd, ": command not found\n", 2);
		ft_exit(127);
	}
	else
	{
		perror("execve");
		ft_exit(1);
	}
}
