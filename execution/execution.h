/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:31:55 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/24 16:26:24 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "../linked_list_function/linked_list.h"
# include "./built_ins/built_in.h"
# include <dirent.h>
# include <sys/types.h>
# include <sys/wait.h>

char	**env_to_arr(void);
void	main_execution(void);
void	execution(t_exec *cmd);
void	execute_simple_cmd(t_exec *cmd);
void	execute_commands(t_exec *cmd, int *fd);
void	dup_and_close(t_exec *cmd);
void	pipes(void);
void	exit_func(t_exec *node);
void	print_execve_errors(t_exec *cmd);
int		fd_error(t_exec *cmd);

#endif