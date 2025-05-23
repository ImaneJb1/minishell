/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_check_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:02:39 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/23 18:47:23 by imeslaki         ###   ########.fr       */
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

char    *get_var_value(char *str, int i)
{
    char *value;

    value = NULL;
    // i++;
    if (str[i] == '=')
        i++;
    else if(str[i] == '+' && str[i + 1] == '=')
        i += 2;
    while (str[i])
        value = join_str_char(value, str[i++]);
    return value;
}

char    *is_valid_key(char *str, int *i)
{
    char *key;

    key = NULL;
    if (!str || !*str)
        return NULL;
    while (is_valid(str[*i]))
    {
        key = join_str_char(key, str[*i]);
        (*i)++;
    }
    if (!str[*i] || str[*i] == '=')
        return key;
    else if(str[*i] == '+' || str[(*i) + 1] == '=')
        return key;
    return NULL;
}
