/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:31:55 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/27 17:17:59 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H 
# define EXECUTION_H

# include "../linked_list_function/linked_list.h"
// # include "../minishell.h"
#include "./built_ins/built_in.h"
#include <sys/types.h>
#include <sys/wait.h>

char    **env_to_arr(void);
void	execute_cmd(t_exec *cmd);
int		execution(t_exec *cmd);
void	dup_and_close(t_exec *cmd);
void	simple_cmd(void);

void	execute_commands(t_exec *cmd, int *fd);
int		pipes(void);
void	main_execution(void);

#endif 