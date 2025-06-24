/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:45:00 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/24 16:21:56 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void	print_array(int *array)
{
	for(int i = 0; array[i] != 1; i++)
		printf("%d ", array[i]);
	printf("\n");
}

void	fill_fdout_arr(t_exec *node)
{
	static int i;

	node->fdout_arr[i] = node->fd_out;
	// print_array(node->fdout_arr);
	i++;
}

static int	is_ambiguous_redir_out(t_cmd *cur)
{
	if ((cur->prev && (cur->prev->type & REDIR_OUT))
		&& !(cur->type & FILE_NAME))
		return (1);
	else if (check_redir(cur, FILE_NAME, REDIR_OUT))
	{
		if (field_count_arg(2) > 1)
			return (1);
	}
	return (0);
}

bool	if_its_outfile(t_cmd *ptr)
{
	if (is_ambiguous_redir_out(ptr))
	{
		is_error(1);
		ft_putstr_fd("bash: ambiguous redirect\n", STDERR_FILENO);
		return (FALSE);
	}
	else if (check_redir(ptr, FILE_NAME, REDIR_OUT))
		return (TRUE);
	return (FALSE);
}

void	open_fd_out(t_cmd *token,  t_exec **node)
{
	int *fd;

	fd = &(*node)->fd_out;
	if (if_its_outfile(token))
	{
		*fd = open(token->content, O_RDWR | O_CREAT | O_TRUNC, 0666);
		if (*fd < 0)
			perror(token->content);
		fill_fdout_arr(*node);
	}
}
