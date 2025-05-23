/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 18:03:36 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/23 17:28:58 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built_in.h"

void    delete_from_env(char *key)
{
    t_env   *env;

    env = *v_env();
    while(env)
    {
        if(ft_strcmp(env->key, key) == 0)
        {
            lst_del_one_env_by_node(env);
            return ;
        }
        env = env->next;
    }
}

void    unset(t_exec	*node)
{
    int i;

    i = 0;
    if(ft_strcmp(node->cmd, "unset") == 0)
    {
        while(node->args[++i])
            delete_from_env(node->args[i]);
    }
}
