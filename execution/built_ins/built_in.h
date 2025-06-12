/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:20:57 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/12 17:22:22 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H

# include "../../linked_list_function/linked_list.h"
# include "../../minishell.h"
# include <limits.h>

# ifndef PATH_MAX
#  define PATH_MAX 4096
# endif


typedef struct s_buitlin
{
	char	*cmd;
	void	(*func)(t_exec *);
}			t_buitin;


void		builtin(t_exec *cmd);
void 		exit_func(t_exec *node);
void    	exit_status_case(char *arg);


//      env
void		env(t_exec *node);


//      export
void		export(t_exec *node);
void		export_arg(char *arg);
char		*get_var_value(char *str, int i);
t_env		*is_existe_in_env(char *key);
char		*the_key(char *str, int *i);
void		add_var_node(t_env **node, char *new_value, char c);
void		appand_var(t_env **node, char *new_value);


//      unset
void		delete_from_env(char *key);
void		unset(t_exec *node);


//		cd && pwd
void		change_directory(char *path);
char		*get_pwd(void);
void		change_pwd_var(void);
void		change_oldpwd_var(char *oldpwd);
void		cd_home(char *oldpwd);
void		cd_back(char *oldpwd);
void		cd(t_exec *node);


//		pwd
void		pwd(t_exec *node);


//		echo
void		echo(t_exec *node);

#endif