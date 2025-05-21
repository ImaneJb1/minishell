/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_spliting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:33:09 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/19 16:03:54 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../parsing.h"

static int	ft_count(char const *s, char *c)
{
	size_t	i;
	size_t	count;
	int		check;

	count = 0;
	i = 0;
	check = 0;
	while (s && s[i])
	{
		if (!ft_strchr(" \t", s[i]) && check == 0)
		{
			check = 1;
			count++;
		}
		if (ft_strchr(" \t", s[i]))
			check = 0;
		i++;
	}
    // if(ft_strchr(" \t", s[0]) && !ft_strchr(" \t", s[ft_strlen(s)]))
    //     count--;
    // else if(!ft_strchr(" \t", s[0]) && ft_strchr(" \t", s[ft_strlen(s)]))
    //     count--;
    // else if(ft_strchr(" \t", s[0]) && ft_strchr(" \t", s[ft_strlen(s)]))
    //     count -= 2;
	return (count);
}

void    insert_into_list(t_cmd *cur, t_data *data)
{
    data->i = 0;
    t_cmd *node;

    node = cur;
    while (data->args[data->i])
    {
        lst_add_one_cmd_by_node(cur, new_cmd_node(data->args[data->i]));
        cur = cur->next;
        data->i++;
    }
    lst_del_one_cmd_by_node(node);
}

int	len_of_word(char *str, int j)
{
	t_data	*data;

	data = init_data();
	while (str[j] && !ft_strchr(" \t", str[j]))
	{
		if(ft_strchr("\"\'", str[j]))
		{
			data->c = str[j++];
			data->count++;
			while (str[j] && str[j] != data->c)
			{
				data->count++;
				j++;
			}
			data->c = 0;
		}
		data->count++;
		j++;
	}
	// while (str[j] && ft_strchr(" \t", str[j]) && j++)
	// 	data->i++;
	// if(str[j] == '$')
	// 	data->count += data->i;
	return data->count;
}

// char  *handl_dollar_sign_case()
// {
	
// }

char	*node_content(char	*str, int *i)
{
	char flag;
	char *word;
	int j;

	flag = 0;
	skip_space(str, i);
	j = (*i);
	word = ft_malloc(len_of_word(str, j) + 1);
	j = 0;
	while (str[*i] && !ft_strchr(" \t", str[*i]))
	{
		if(ft_strchr("\"\'", str[*i]))
		{
			flag = str[*i];
			word[j++] = str[(*i)++];
			while (str[*i] && str[*i] != flag)
				word[j++] = str[(*i)++];
			flag = 0;
		}
		word[j++] = str[(*i)++];
	}
	// word = handl_dollar_sign_case();
	skip_space(str, i);
	return word;
}

void	split_the_field(t_cmd *cmd)
{
	t_data *data;
	t_cmd	*cur;

	data = init_data();
	data->content = cmd->content;
	cur = cmd;
	while (data->content[data->i])
	{
		data->str = node_content(data->content, &data->i);
		lst_add_one_cmd_by_node(cmd, new_cmd_node(ft_strdup(data->str)));
		ft_free(data->str);
		cmd = cmd->next;
	}
	lst_del_one_cmd_by_node(cur);
}

void	field_spliting(void)
{
	t_cmd	*head;

	head = *v_cmd();
	while (head)
	{
		if ((head->type & VARIABLE) && !(head->type & DELIMITER))
			split_the_field(head);
		head = head->next;
	}
}
