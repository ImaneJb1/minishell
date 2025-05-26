/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:31:55 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/26 11:11:52 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H 
# define EXECUTION_H

# include "../linked_list_function/linked_list.h"
# include "../minishell.h"
#include "./built_ins/built_in.h"

char            **env_to_arr(void);

#endif 