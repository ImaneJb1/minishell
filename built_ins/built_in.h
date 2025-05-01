/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:20:57 by imeslaki          #+#    #+#             */
/*   Updated: 2025/04/29 18:05:34 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H

# include "../linked_list_function/linked_list.h"
# include "../minishell.h"

//      env
int		env_built_in(void);

//      export
int		export_built_in(void);

//      unset
int		unset(void);
void	unset_value_from_env(char *key);

#endif