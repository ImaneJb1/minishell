/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_var_from_env.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:59:44 by imeslaki          #+#    #+#             */
/*   Updated: 2025/04/30 22:24:32 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built_in.h"

void	unset_value_from_env(char *key)
{
	t_env	*cur_env;

	if (!v_env() || !(*v_env()) || !key)
		return ;
    index_the_env_list();
	cur_env = *v_env();
	while (cur_env)
	{
		if (ft_strcmp(cur_env->key, key) == 0)
			return lst_del_one_env(cur_env->index);
		cur_env = cur_env->next;
	}
}

int     unset(void)
{
    t_cmd *cmd;
    t_type types;

    if(!v_env() || !v_cmd() || !(*v_env()) || !(*v_cmd()))
        return 1;
    cmd = *v_cmd();
    if(lstsize_cmd(cmd) <= 1)
        return 1;
    cmd = cmd->next;
    types = WORD | CMD_ARG | DOUBLE_Q | SINGLE_Q;
    while(cmd)
    {
        if(cmd->type & types)
            unset_value_from_env(cmd->content);
        cmd = cmd->next;
    }
    index_the_env_list();
    return 1;
}
