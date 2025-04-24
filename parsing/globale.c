/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globale.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 02:10:19 by imeslaki          #+#    #+#             */
/*   Updated: 2025/04/21 19:41:11 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_cmd   **v_cmd(void)
{
    static t_cmd *cmd;

    return &cmd;
}

t_env   **v_env(void)
{
    static t_env *env;

    return &env;
}

t_pipe  *v_pipe(void)
{
    static  t_pipe pipe;

    return &pipe;
}
