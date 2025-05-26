/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:30:04 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/25 15:30:37 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "execution.h"
char ***env_arr(void)
{
    static char **env;
    
    return &env;
}

void    env_to_arr(void)
{
    t_env *env_list;
    char  **env_array;
    char *str;
    int i;

    env_list = *v_env();
    env_array = *env_arr();
    str = NULL;
    env_array = ft_malloc(sizeof(char *) * (lstsize_env(env_list) + 1));
    i = 0;
    while (env_list)
    {
        str = ft_strjoin(str, env_list->key);
        str = join_str_char(str, '=');
        str = ft_strjoin(str, env_list->value);
        env_array[i] = str;
        i++;
        env_list = env_list->next;
    }
    env_array[i] = NULL;
}

// int main()
// {
//     char  **env_array;
//     env_array = *env_arr();
//     printf("%s\n",env_array[0]);
// }
