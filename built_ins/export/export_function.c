/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:46:05 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/19 14:42:02 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built_in.h"

char    *check_key(char *str, int *i)
{
    char *key;

    key = NULL;
    if (!str)
        return NULL;
    while (is_valid(str[*i]))
    {
        key = join_str_char(key, str[*i]);
        (*i)++;
    }
    if (str[*i] == '=')
        return key;
    if (str[*i] == '+' && str[(*i) + 1] == '=')
    {
        if (!append_existe_var(str, key, *i))
            return key;
    }
    return NULL;
}

char *extracte_str(char *str, int i)
{
    char *value;

    value = NULL;
    i++;
    if (str[i] == '=')
        i++;
    while (str[i])
        value = join_str_char(value, str[i++]);
    return value;
}

void    export_arg(char *arg)
{
    char *key;
    char *value;
    t_env *existe;
    int i;

    i = 0;
    existe = NULL;
    key = check_key(arg, &i);
    if (!key)
        return;
    value = extracte_str(arg, i);
    if (!value)
        return;
    existe = is_existe_in_env(key);
    if(existe)
    {
        existe->value = value;
        return ;
    }
    add_to_env(key, value);
}

void    export_built_in(char *cmd, char **args)
{
    int i;

    i = 0;
    if (!cmd || !args || !(*args))
        return;
    if (ft_strcmp(cmd, "export") == 0)
    {
        while (args[++i])
            export_arg(args[i]);
    }
    else
        return;
}
