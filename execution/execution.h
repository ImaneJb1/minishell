/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:31:55 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/25 14:05:43 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H 
# define EXECUTION_H

# include "../linked_list_function/linked_list.h"
# include "../minishell.h"
#include "./built_ins/built_in.h"
#include "non_built_ins/pipex.h"

char ***env_arr(void);
void    env_to_arr(void);
#endif 