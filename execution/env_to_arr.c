/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:30:04 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/12 17:19:30 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "execution.h"

char    **env_to_arr(void)
{
    t_env *env_list;
    char  **env_array;
    char *str;
    int i;

    env_list = *v_env();
    str = NULL;
    env_array = ft_malloc(sizeof(char *) * (lstsize_env() + 1));
    i = 0;
    while (env_list)
    {
        str = ft_strdup(env_list->key);
        str = join_str_char(str, '=');
        env_array[i++] = ft_strjoin(str, env_list->value);
        ft_free(str);
        str = NULL;
        env_list = env_list->next;
    }
    env_array[i] = NULL;
    return env_array;
}
