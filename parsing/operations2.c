/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:54:45 by imeslaki          #+#    #+#             */
/*   Updated: 2025/04/18 11:54:14 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"


void	protect_singl_quoat(char *str, int *i, int flag)
{
	while (str[*i])
	{
		if(( str[*i] != '\'' && flag == 0) || (!ft_strchr(" \"\'|<>$", str[*i]) && flag == 1))
        {
			add_to_list(str[*i],1);
			(*i)++;
		}
		else if (str[*i] == '\'' && !ft_strchr(" |<>$", str[*i + 1]))
		{
			flag = 1;
			add_to_list(str[*i],1);
			(*i)++;
		}
		else
        {
			if(str[*i] == '\'' && ft_strchr(" |<>$", str[*i + 1]))
			{
				add_to_list(str[*i],1);
				(*i)++;
			}
		    break;
		}
	}
}

int	is_singl_quote(char *str, int *i)
{
	if (str[*i] && str[*i] == '\'')
	{
        add_to_list(str[*i],1);
		(*i)++;
		protect_singl_quoat(str, i, 0);
		add_to_list(0,2);
		add_to_list(0,0);
        return 1;
	}
    return 0;
}

void	protect_double_quoat(char *str, int *i, int flag)
{
	while (str[*i])
	{
		if(( str[*i] != '\"' && flag == 0) || (!ft_strchr(" \"\'|<>$", str[*i]) && flag == 1))
        {
			add_to_list(str[*i],1);
			(*i)++;
		}
		else if (str[*i] == '\"' && !ft_strchr(" |<>$", str[*i + 1]))
		{
			flag = 1;
			add_to_list(str[*i],1);
			(*i)++;
		}
		else
        {
			if(str[*i] == '\"' && ft_strchr(" |<>$", str[*i + 1]))
			{
				add_to_list(str[*i],1);
				(*i)++;
			}	
		    break;
		}
	}
}

int	is_double_quote(char *str, int *i)
{
	if (str[*i] == '\"')
	{
        add_to_list(str[*i],1);
		(*i)++;
		protect_double_quoat(str, i, 0);
		add_to_list(0,2);
		add_to_list(0,0);
        return 1;
	}
    return 0;
}

int	is_var(char *str, int *i)
{ 
	if ( str[*i] == '$' && ft_strchr(" |<>", str[*i + 1]))
	{
        add_to_list(str[*i],1);
		(*i)++;
		add_to_list(0,2);
		add_to_list(0,0);
        return 1;
	}
	else if(str[*i] == '$' && !ft_strchr(" |<>", str[*i + 1]))
	{
		add_to_list(str[*i],1);
		(*i)++;
		while(str[*i] && ft_strchr(" |<>",str[*i]))
		{
			add_to_list(str[*i],1);
			(*i)++;
		}
	}
    return 0;
}
