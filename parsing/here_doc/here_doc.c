/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:51:24 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/21 18:31:45 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void    var_content(char   *str, t_data *data,int *i)
{
    char    *key;

    key = NULL;
    while (str[*i] && is_valid(str[*i]))
        data->key = join_str_char(data->key, str[*i++]);
    data->value = get_value_from_env(data->key);
	if (!data->value)
		return ;
    data->j = 0;
	while (data->value[data->j])
		data->content = join_str_char(data->content, data->value[data->j++]);
}

char    *expand(char *str, char *content, int *i)
{
    t_data *data;

    data = init_data();
    data->content = content;
    while(str[*i])
    {
        if(str[(*i) + 1] == '$')
        {
            data->content = ft_strjoin(data->content, "$$");
            (*i) += 2;
        }
        else
            var_content(str, data, i);
    }
    return data->content;
}

char    *expand_here_doc_var(char *str)
{
    t_data *data;

    data = init_data();
    while (str[data->i])
    {
        if(str[data->i] == '$')
        {
            data->content = expand(str, data->content, &data->i);
            continue;
        }
        data->content = join_str_char(data->content, str[data->i++]);
    }
    return data->content;
}

int open_her_doc(t_cmd *del)
{
    t_data *data;

    data = init_data();
    data->fd = open("", O_CREAT | O_RDWR | O_TRUNC, 0666);
    if(data->fd < 0)
       return (perror("open failed"), 0);
    if((!del->type & SINGLE_Q) && (!del->type & DOUBLE_Q))
        data->flag = 1;
    while (1)
    {
        data->str = readline(" >> ");
        if(!data->str || !*data->str)
            continue;
        if(ft_strcmp(del,data->str) == 0)
            break;
        if(data->flag == 1)
            data->str = expand_here_doc_var(data->str);
        ft_putstr_fd(join_str_char(data->str, '\n'), data->fd);
    }
    
    data->args[data->i++] = NULL;
    return 1;
}

void here_doc(t_cmd *del)
{
    t_data *data;

    data = init_data();
    data->fd = open("", O_CREAT | O_RDWR | O_TRUNC, 0666);
    if(data->fd < 0)
       return (perror("open failed"), 0);
    read_here_doc_input(data->fd, del);
    // data->args = open_her_doc(del);
}