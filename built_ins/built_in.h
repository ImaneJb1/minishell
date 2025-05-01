/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:20:57 by imeslaki          #+#    #+#             */
/*   Updated: 2025/04/27 22:39:02 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H

#include "../linked_list_function/linked_list.h"
#include "../minishell.h"
#include <limits.h>
#include <linux/limits.h>


//      env
void	env_built_in(void);
void    print_working_directory(void);
void    change_directory(char *path);
#endif