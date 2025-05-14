/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 18:03:36 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/14 11:35:41 by imeslaki         ###   ########.fr       */
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

void    unset(char *cmd, char **args)
{
    int i;

    i = 0;
    if(ft_strcmp(cmd, "unset") == 0)
    {
        while(args[++i])
            delete_from_env(args[i]);
    }
    else
        return ;
}
    