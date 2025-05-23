/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:30:04 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/23 16:51:26 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "execution.h"
char ***env_arr(void)
{
    static **env;
    
    return &env;
}

void    env_to_arr(void)
{
    t_env *env_list;
    char  **env_array;
    int i;

    env_list = *v_env();
    env_array = *env_arr();
    env_list = ft_malloc(sizeof(char *) * (lstsize_env(env_list) + 1));
    i = 0;
    while (env_list)
    {
        env_array[i++] = ft_strdup(env_list);
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
