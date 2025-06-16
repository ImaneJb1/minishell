/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:07:27 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/16 15:22:34 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing/parsing.h"

int	is_error(int flag)
{
	static int	i;

	if (flag == 0)
		i = 0;
	else if (flag == 1)
		i = 1;
	return (i);
}

int	handle_exec_error(void)
{
	not_first_cmd(0);
	is_error(0);
	return (0);
}

void	print_error_to_stderr(char *s1, char *s2, char *s3, int fd)
{
	ft_putstr_fd(s1, fd);
	ft_putstr_fd(s2, fd);
	ft_putstr_fd(s3, fd);
}
