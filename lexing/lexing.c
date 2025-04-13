/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:47:07 by imeslaki          #+#    #+#             */
/*   Updated: 2025/04/11 18:48:28 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Header.h"

char    **splitting(char *line)
{
	char **result;

	result = super_split(line, '|');
	
	return(result);
}

t_struct	*new_node(char *value, t_type type)
{
	t_struct	*elem;

	elem = malloc(sizeof(t_struct));
	if (!elem)
		return (NULL);
	elem->value = value;
	elem->type = type;
	elem->next = NULL;
	return (elem);
}

void 	reading_from_input(void)
{
	char *input;

	while(1)
	{
		input = readline("minishell>> ");
		if (!input)
			break;
		if (*input)
			add_history(input);
		free(input);
	}
}

int	main(void)
{
	char **input = splitting("< file cat | ls |||||a| echo \"hello |||||| m \" ");
	for(int i = 0; input[i]; i++)
		printf("{%s}\n", input[i]);
	return (0);
}
