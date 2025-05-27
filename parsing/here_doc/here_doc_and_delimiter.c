/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_and_delimiter.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:23:30 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/27 17:09:05 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void    get_delimiter(t_cmd **cmd)
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
    del = unquoted_one_cmd(del);
    (*cmd)->content = del;
}

void    write_in_here_doc_file(t_cmd  *del, t_data *info, int *fd)
{
    t_data *data;
    

    data = init_data();
    *fd = open(info->word, O_CREAT | O_RDWR | O_TRUNC, 0666);
    if(*fd < 0)
       return (perror(info->word));
    if (!(del->type & (SINGLE_Q | DOUBLE_Q)))
        data->flag = 1;
    while (1)
    {
        data->str = readline("  >> ");
        if(!data->str)
            continue;
        if (ft_strcmp(del->content, data->str) == 0)
            break;
        check_expand_and_put_in_file(data, *fd);
    }
    close(*fd);
}

void    open_fd_heredoc(t_cmd *token, int *fd)
{
    t_data *data;
    char    *fd_file_name;
    static int here_num;

    data = init_data();
    fd_file_name = NULL;
    if(token->type & DELIMITER)
    {
        data->word = ft_strjoin("/tmp/", ft_itoa(here_num++));
        *fd = open(data->word, O_CREAT | O_RDWR | O_TRUNC, 0666);
        if(*fd < 0)
            return (perror(fd_file_name));
        data->pid = fork();
        if(data->pid == 0)
        {
            get_delimiter(&token);
            write_in_here_doc_file(token, data, fd);
            ft_free_all();
            exit(1);
        }
        wait(NULL);
    }
}
