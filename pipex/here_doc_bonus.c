/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:33:08 by imeslaki          #+#    #+#             */
/*   Updated: 2025/03/08 03:11:03 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	write_in_file(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s || fd < 0)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	is_delemiter(char *content, char *delemiter)
{
	char	*del_whith_new_line;

	del_whith_new_line = ft_strjoin_bonus(delemiter, "\n");
	if (ft_strcmp(content, delemiter) == 1)
	{
		free(del_whith_new_line);
		return (1);
	}
	else if (ft_strcmp(content, del_whith_new_line) == 1)
	{
		free(del_whith_new_line);
		return (1);
	}
	free(del_whith_new_line);
	return (0);
}

int	here_doc(char *arg, t_data *data)
{
	int		fd;
	char	*content;

	fd = 0;
	content = NULL;
	(void)arg;
	fd = open("here_doc", O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (fd == -1)
	{
		close(data->pipes[0][1]);
		data->pipes[0][1] = -1;
		free_2d_arry_of_integers_bonus(data->pipes, data->number_of_loops);
		free(data->pid);
		errors_bonus("here_doc", data, -1);
	}
	while (is_delemiter(content, data->delemiter) == 0)
	{
		write_in_file(content, fd);
		free(content);
		content = get_next_line(0, data->delemiter);
	}
	free(content);
	return (fd);
}
