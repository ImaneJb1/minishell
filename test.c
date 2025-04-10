/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:47:07 by imeslaki          #+#    #+#             */
/*   Updated: 2025/04/10 17:47:08 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include "parsing.h"


char    check(char *line)
{

}

t_line  *list()
{
    
}

int	main(void)
{
	char *input;

	while (1)
	{
		input = readline("minishell$ ");
		if (!input)
			break;
		if (*input)
			add_history(input);
		check(input);
		free(input);
	}
	printf("exit\n");
	return (0);
}
