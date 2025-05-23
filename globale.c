/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globale.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 02:10:19 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/13 10:23:05 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

    t_exec  **v_exec(void)
{
    static t_exec *exec;

    return &exec;
}

t_pipe  **v_pipe(void)
{
    static  t_pipe *pipe;

    return &pipe;
}
