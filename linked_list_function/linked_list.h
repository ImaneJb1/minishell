/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 21:14:24 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/16 15:21:39 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include "../minishell.h"
# include "../parsing/parsing.h"

//      cmd list
t_cmd	*new_cmd_node(char *value);
void	lstadd_cmd_back(t_cmd **lst, t_cmd *new);
t_cmd	*lstlast_cmd(void);
void	lstclear_cmd(void);
void	lst_del_one_cmd(t_cmd *cur);
void	lst_add_one_cmd(t_cmd *cur, t_cmd *new);

//      env list
t_env	*new_env_node(char *key, char *value);
void	lstadd_env_back(t_env **lst, t_env *new);
t_env	*lstlast_env(void);
int		lstsize_env(void);
void	lst_del_one_env_by_node(t_env *cur);

//      exec list
t_exec	*new_exec_node(void);
void	lstadd_exec_back(t_exec **lst, t_exec *new);
t_exec	*lstlast_exec(void);
int		lstsize_exec(void);
void	lstclear_exec(void);

#endif