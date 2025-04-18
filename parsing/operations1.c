/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:56:33 by imeslaki          #+#    #+#             */
/*   Updated: 2025/04/18 20:02:38 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "parsing.h"

int	is_arg(char *str, int *i)
{
	if( !ft_strchr(" \"\'|<>$", str[*i]))
	{
		if(str[(*i) - 1] == ' ')
			add_to_list(str[(*i) - 1],1);
		while (str[*i] && !ft_strchr(" |<>$", str[*i]))
		{
			if(str[*i] == '\"')
			{
				add_to_list(str[*i], 1);
				(*i)++;
				protect_double_quoat(str, i, 0);
			}
			else if(str[*i] == '\'')
			{
				add_to_list(str[*i], 1);
				(*i)++;
				protect_singl_quoat(str, i, 0);
			}
			else
			{
				add_to_list(str[*i], 1);
				(*i)++;
			}
		}
		add_to_list(0,2);
		add_to_list(0,0);
		return 1;
	}
	return 0;
}



int	is_reder_in(char *str, int *i)
{
	if (str[*i] && str[*i] == '<')
	{
		if(str[(*i) - 1] == ' ')
			add_to_list(str[(*i) - 1],1);
        add_to_list(str[*i],1);
		(*i)++;
		add_to_list(0,2);
		add_to_list(0,0);
		return 1;
	}
	return 0;
}

int	is_reder_out(char *str, int *i)
{
	if (str[*i] && str[*i] == '>')
	{
		if(str[(*i) - 1] == ' ')
			add_to_list(str[(*i) - 1],1);
        add_to_list(str[*i],1);
		(*i)++;
		add_to_list(0,2);
		add_to_list(0,0);
		return 1;
	}
	return 0;
}

int	is_reder_out_append(char *str, int *i)
{
	if (str[*i] && str[*i + 1] && str[*i] == '>' && str[*i + 1] == '>')
	{
		if(str[(*i) - 1] == ' ')
			add_to_list(str[(*i) - 1],1);
        add_to_list(str[*i],1);
		add_to_list(str[*i + 1],1);
		(*i) += 2;
		add_to_list(0,2);
		add_to_list(0,0);
		// if(str[*i] &&  str[*i] == '>')
		// 	printf("\nError : >>>\n");
		return 1;
	}
	return 0;
}

int	is_heredoc(char *str, int *i)
{
	if (str[*i] && str[*i + 1] && str[*i] == '<' && str[*i + 1] == '<')
	{
		if(str[(*i) - 1] == ' ')
			add_to_list(str[(*i) - 1],1);
        add_to_list(str[*i],1);
		add_to_list(str[*i + 1],1);
		(*i) += 2;
		add_to_list(0,2);
		add_to_list(0,0);
		return 1;
	}
	return 0;
}

// int	is_arg(char *str, int *i)
// {
// 	if(!ft_strchr(" \'\"|<>$", str[*i]))
// 	{
// 		while (!ft_strchr(" |<>$", str[*i]))
// 		{
// 			if(str[*i] == '\"')
// 			{
// 				add_to_list(str[*i], 1);
// 				(*i)++;
// 				protect_double_quoat(str, i, 0);
// 			}
// 			else if(str[*i] == '\'')
// 			{
// 				add_to_list(str[*i], 1);
// 				(*i)++;
// 				protect_singl_quoat(str, i, 0);
// 			}
// 			else
// 				add_to_list(str[*i], 1);
// 			(*i)++;
// 		}
// 		add_to_list(0, 2);
// 		add_to_list(0, 0);
// 		return 1;
// 	}
// 	return 0;
// }



