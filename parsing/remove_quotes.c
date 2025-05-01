/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:22:01 by imeslaki          #+#    #+#             */
/*   Updated: 2025/04/29 22:03:14 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char    *handle_one_cmd(char *str)
{
    int i;
    int j;
    char *command;
    char c;

    i = 0;
    j = 0;
    c = '\0';
    command = NULL;
    while(str[i])
    {
        if(c == 0 && ft_strchr("\"\'", str[i]))
            c = str[i++];
        else if(c == 0 && !ft_strchr("\"\'", str[i]))
            command = join_str_char(command, str[i++]);
        else if(c != 0 && c != str[i])
            command = join_str_char(command, str[i++]);
        else if(c != 0 && c == str[i])
        {
            c = 0; 
            i++;
        }
    }
    return command;
}

void    remove_quotes(void)
{
    t_cmd *cmd;

    if(!v_cmd() || !(*v_cmd()))
        return ;
    cmd = *v_cmd();
    while(cmd)
    {
        if(cmd->type & (DOUBLE_Q | SINGLE_Q))
            cmd->content = handle_one_cmd(cmd->content);
        cmd = cmd->next;
    }
}
