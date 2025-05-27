/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_spliting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:33:09 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/26 15:21:05 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../parsing.h"

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
	return data->count;
}

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
	skip_space(str, i);
	return word;
}

void	split_the_field(t_cmd *cmd)
{
	t_data *data;
	t_cmd	*cur;
	t_cmd	*node;
	int		flag;

	flag = 0;
	node = NULL;
	data = init_data();
	data->content = cmd->content;
	cur = cmd;
	while (data->content[data->i])
	{
		data->str = node_content(data->content, &data->i);
		node = new_cmd_node(ft_strdup(data->str));
		if(flag == 0)
			node->type = CMD;
		else
			node->type = CMD_ARG;
		flag = 1; 
		lst_add_one_cmd_by_node(cmd, node);
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
