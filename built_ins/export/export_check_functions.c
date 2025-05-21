/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_check_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:02:39 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/21 09:57:43 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built_in.h"

t_env   *is_existe_in_env(char *key)
{
    t_env *env;

    env = *v_env();
    while (env)
    {
        if (ft_strcmp(env->key, key) == 0)
            return env;
        env = env->next;
    }
    return NULL;
}

int append_existe_var(char *str, char *Key, int i)
{
    char *value;
    t_env *env;

    env = *v_env();
    value = extracte_str(str, i);
    while (env)
    {
        if (ft_strcmp(env->key, Key) == 0)
        {
            i = 0;
            while (value[i])
                env->value = join_str_char(env->value, value[i++]);
            return 1;
        }
        env = env->next;
    }
    return 0;
}
