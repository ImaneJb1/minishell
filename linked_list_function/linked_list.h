/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 21:14:24 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/27 17:16:11 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include "../minishell.h"
# include "../parsing/parsing.h"

//		linked list functions

//          cmd list
void	index_the_cmd_list(void);
t_cmd	*new_cmd_node(char *value);
void	lstadd_cmd_back(t_cmd **lst, t_cmd *new);
void	lstadd_cmd_front(t_cmd **lst, t_cmd *new);
t_cmd	*find_cmd_by_index(int index);
int		lstsize_cmd(t_cmd *lst);
t_cmd	*lstlast_cmd(void);
void	lstclear_cmd(void);
void	lst_del_one_cmd_by_node(t_cmd *cur);
// void	lst_del_one_cmd(int index);
void	lst_add_one_cmd_by_node(t_cmd *cur, t_cmd *new);

//          env list
t_env	*new_env_node(char *key, char *value);
void	lstadd_env_back(t_env **lst, t_env *new);
void	lstadd_env_front(t_env **lst, t_env *new);
t_env	*lstlast_env(void);
int		lstsize_env(void);
void	lstclear_env(void);
t_env	*find_env_by_index(int index);
void	lst_add_one_env(t_env *new, int index);
void	lst_del_one_env_by_node(t_env *cur);
void	lstadd_one_env_by_node(t_env *new, t_env *cur);
void	index_the_env_list(void);

//          exec list
t_exec	*new_exec_node(void);
void	lstadd_exec_back(t_exec **lst, t_exec *new);
void	lstadd_exec_front(t_exec **lst, t_exec *new);
t_exec	*lstlast_exec(void);
int		lstsize_exec(void);
t_exec	*find_exec_by_index(int index);
void	lst_add_one_exec(t_exec *new, int index);
void	lst_del_one_exec_by_node(t_exec *cur);
// void	index_the_exec_list(void);
void	lstclear_exec(void);



#endif