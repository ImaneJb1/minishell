/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_checkers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:53:48 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/12 17:02:18 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

char	*get_value_from_env(char *key)
{
	t_env	*cur_env;

	if (!v_env() || !(*v_env()) || !key)
		return (NULL);
	cur_env = *v_env();
	while (cur_env)
	{
		if (ft_strcmp(cur_env->key, key) == 0)
			return (ft_strdup(cur_env->value));
		cur_env = cur_env->next;
	}
	return (NULL);
}

char	*inside_quote(char *command, char *content, int *i, char sp)
{
	char	c;

	c = '\0';
	while (content[*i])
	{
		if (content[*i] == sp && c == '\0')
		{
			command = join_str_char(command, content[*i]);
			c = content[(*i)++];
		}
		else if (content[*i] == sp && c != '\0')
		{
			command = join_str_char(command, content[(*i)++]);
			c = '\0';
		}
		else if (c != '\0')
			command = join_str_char(command, content[(*i)++]);
		else
			break ;
	}
	return (command);
}

int	check_double_quote(char c, int j)
{
	if (j == 0 && c == '\"')
		return (1);
	else if (j == 1 && c != '\"')
		return (1);
	else
		return (0);
}

int is_valid(char c)
{
	if(ft_isdigit(c) || is_alpha(c) || c == '_')
		return 1;
	return 0;
}

int is_var_inside_quote(char *c, int i, int j)
{
	if (c[i] == '$' && is_valid(c[i + 1]))
		return (1);
	if(c[i] == '$' && c[i + 1] == '?')
		return (1);
	if(j == 0 && c[i] == '$' && ft_strchr("\"\'", c[i + 1]))
		return (1);
	return (0);
}
