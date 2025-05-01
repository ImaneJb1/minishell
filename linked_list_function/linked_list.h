/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 21:14:24 by imeslaki          #+#    #+#             */
/*   Updated: 2025/04/29 17:37:06 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include "../minishell.h"
# include "../parsing/parsing.h"

//		linked list functions

//          cmd list
void	index_the_cmd_list(void);
t_cmd	*lst_new_cmd_node(char *value);
void	lstadd_cmd_back(t_cmd **lst, t_cmd *new);
void	lstadd_cmd_front(t_cmd **lst, t_cmd *new);
t_cmd	*find_cmd_by_index(int index);
int		lstsize_cmd(t_cmd *lst);
t_cmd	*lstlast_cmd(t_cmd *lst);
void	lstclear_cmd(void);
void	lst_del_one_cmd(int index);
void	lst_add_one_cmd(t_cmd *new, int index);

//          env list
t_env	*new_env_node(char *key, char *value);
void	lstadd_env_back(t_env **lst, t_env *new);
void	lstadd_env_front(t_env **lst, t_env *new);
t_env	*lstlast_env(t_env *lst);
int		lstsize_env(t_env *lst);
void	lstclear_env(void);
t_env	*find_env_by_index(int index);
void	lst_add_one_env(t_env *new, int index);
void	lst_del_one_env(int index);
void	index_the_env_list(void);

#endif