/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_delimiter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:23:30 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/15 11:40:35 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"


void    true_del(t_cmd **cmd)
{
    int i;
    char *str;
    char *del;

    i = 0;
    del = NULL;
    str = (*cmd)->content;
    while(str[i])
    {
        if(str[i] == '$' && str[i + 1] == '$')
        {
            del = ft_strjoin(del, "$$");
			i += 2;
        }
            if(str[i] == '\'')
            del = inside_quote(del, str, &i, '\'');
        if(str[i] == '\"')
            del = inside_quote(del, str, &i, '\"');
        else if(str[i] == '$' && ft_strchr("\"\'", str[i + 1]))
            i++;   
        else
            del = join_str_char(del, str[i++]);
    }
    (*cmd)->content = del;
}

void    change_the_correct_del(void)
{
    t_cmd *cmd;

    cmd = *v_cmd();
    while(cmd)
    {
        if(cmd->type & DELIMITER)
            true_del(&cmd);
        cmd = cmd->next;
    }
}

