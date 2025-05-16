/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:20:57 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/14 11:36:04 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H

# include "../linked_list_function/linked_list.h"
# include "../minishell.h"
# include <limits.h>

#ifndef PATH_MAX
#define PATH_MAX 4096
#endif

typedef struct s_data {
    int i;
    int j;
    char line;
}   t_data;

//      env
void	env_built_in(char *cmd, char **args);
void	add_to_env(char *key, char *value);

//      export
void		export_built_in(char *cmd, char **args);
char        *extracte_str(char *str, int i);
t_env       *is_existe_in_env(char *key);
char        *check_key(char *str, int *i);
int         append_existe_var(char *str, char *Key, int i);

//      unset
void    delete_from_env(char *key);
void    unset(char *cmd, char **args);

//cd pwd
void    change_directory(char *path, char **env);
char    *get_pwd(void);
void    change_pwd_var(char **env);
void    change_oldpwd_var(char *oldpwd, char **env);
void    cd_home(char *path);

//pwd
void    print_working_directory(void);
#endif