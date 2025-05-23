/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:20:57 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/23 18:48:35 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H

# include "../execution.h"
# include <limits.h>

#ifndef PATH_MAX
#define PATH_MAX 4096
#endif

// typedef struct s_bdata {
//     int i;
//     int j;
//     char line;
// }   t_bdata;

typedef struct s_buitlin
{
	char *cmd;
	void (*func)(t_exec *);
}	t_buitin;

//      env
void	env(t_exec	*node);
void	add_to_env(char *key, char *value);

//      export
void		export(t_exec	*node);
void    	export_arg(char *arg);
char        *get_var_value(char *str, int i);
t_env       *is_existe_in_env(char *key);
char        *is_valid_key(char *str, int *i);
void    	add_var_node(t_env **node, char *new_value);
void    	appand_var(t_env **node, char *new_value);

//      unset
void    delete_from_env(char *key);
void    unset(t_exec	*node);

//cd pwd
void    change_directory(char *path);
char    *get_pwd(void);
void    change_pwd_var();
void    change_oldpwd_var(char *oldpwd);
void    cd_home(char *oldpwd);
void    cd_back(char *oldpwd);
void    cd(t_exec *node);

//pwd
void    pwd(t_exec *node);

//echo
void    echo(t_exec *node);
//execution
void	builtin(t_exec *cmd);
#endif