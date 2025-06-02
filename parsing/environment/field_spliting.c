/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_spliting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:33:09 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/02 15:09:16 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

int	len_of_word(char *str, int j)
{
	t_data	*data;

	data = init_data();
	while (str[j] && !ft_strchr(" \t", str[j]))
	{
		if (ft_strchr("\"\'", str[j]))
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
	return (data->count);
}

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

void	skip_quotes(char *str, int *i)
{
	char	c;

	if (ft_strchr("\'\"", str[*i]))
	{
		c = str[*i];
		(*i)++;
		while (str[*i] && str[*i] != c)
			(*i)++;
		if (str[*i] == c)
			(*i)++;
	}
}
int	is_not_field(char *content)
{
	int	i;

	i = 0;
	if (ft_strchr(" \t", content[i]))
		return (0);
	while (content[i])
	{
		// skip_quotes(content, &i);
		while (content[i] && !ft_strchr(" \t\'\"", content[i]))
			i++;
		skip_quotes(content, &i);
		if (!content[i])
			return (1);
		if (ft_strchr(" \t", content[i]))
			return (0);
	}
	return (0);
}

// int		is_not_field(char const *s, char *c)
// {
// 	int	i;
// 	int	count;

// 	i = 0;
// 	count = 0;
// 	if(ft_strchr(c, s[i]))
// 		return (1);
// 	while (s && s[i])
// 	{
// 		while (s[i] && ft_strchr(c, s[i]))
// 			i++;
// 		if (s[i])
// 		{
// 			count++;
// 			while (s[i] && !ft_strchr(c, s[i]))
// 				i++;
// 		}
// 	}
// 	return (count);
// }

void	split_the_field(t_cmd *cmd)
{
	t_data	*data;
	t_cmd	*cur;
	t_cmd	*node;
	int		flag;

	flag = 0;
	node = NULL;
	data = init_data();
	data->content = cmd->content;
	cur = cmd;
	if (is_not_field(data->content))
		return ;
	while (data->content[data->i])
	{
		data->str = node_content(data->content, &data->i);
		node = new_cmd_node(ft_strdup(data->str));
		if (flag == 0)
		{
			node->type = CMD;
			if (ft_strchr(node->content, '/'))
				node->type |= PATH;
		}
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
