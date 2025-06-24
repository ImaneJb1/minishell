/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_spliting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:33:09 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/24 21:48:13 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

char	*node_content(char *str, int *i)
{
	char	flag;
	char	*word;
	int		j;

	flag = 0;
	skip_space(str, i);
	j = (*i);
	word = ft_malloc(len_of_word(str, j) + 1);
	j = 0;
	while (str[*i] && !ft_strchr(" \t", str[*i]))
	{
		if (ft_strchr("\"\'", str[*i]))
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
	return (word);
}
void	add_quate_if_exist(t_cmd **node)
{
	int i;

	i = 0;
	while ((*node)->content[i])
	{
		if((*node)->content[i] == '\'')
		{
			(*node)->type |= SINGLE_Q;
			return ;
		}
		else if((*node)->content[i] == '\"')
		{
			(*node)->type |= DOUBLE_Q;
			return ;
		}		
		i++;
	}
}
void	add_types(t_cmd **node, int *flag, t_type type)
{
	add_quate_if_exist(node);
	if (*flag == 0)
	{
		field_count_arg(1);
		(*node)->type |= type;
		(*node)->type |= CMD;
		(*node)->type |= CMD_ARG;
		if (ft_strchr((*node)->content, '/'))
			(*node)->type |= PATH;
	}
	else
	{
		field_count_arg(1);
		(*node)->type |= CMD_ARG;
	}
	*flag = 1;
}

void	split_the_field(t_cmd *cmd)
{
	t_data	*data;
	t_cmd	*cur;
	t_cmd	*node;
	t_type	type;
	int		flag;

	flag = 0;
	node = NULL;
	data = init_data();
	data->content = cmd->content;
	cur = cmd;
	if (is_not_field(data->content))
		return ;
	type = cmd->type;
	while (data->content[data->i])
	{
		data->str = node_content(data->content, &data->i);
		node = new_cmd_node(ft_strdup(data->str));
		add_types(&node, &flag, type);
		lst_add_one_cmd(cmd, node);
		ft_free(data->str);
		cmd = cmd->next;
	}
	lst_del_one_cmd(cur);
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
