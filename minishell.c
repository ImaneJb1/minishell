/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imane <imane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:31:31 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/25 11:59:00 by imane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parsing/parsing.h"
#include "execution/built_ins/built_in.h"
#include "minishell.h"

int		g_exit_status;

void	create_env_and_handle_signals(char **env)
{
	signal(SIGINT, handle_sig_int);
	signal(SIGQUIT, SIG_IGN);
	create_environment(env);
}

void	handle_ctr_d(char *str)
{
	free(str);
	clear_history();
	// ft_putstr_fd("exit\n", 1);
	ft_exit(g_exit_status);
}

// int	main(int argc, char const *argv[], char **env)
// {
// 	char	*str;

// 	(void)argv;
// 	(void)argc;
// 	create_env_and_handle_signals(env);
// 	while (1)
// 	{
// 		str = readline("Minishell $>: ");
// 		if (!str)
// 			handle_ctr_d(str);
// 		if (!*str)
// 		{
// 			free(str);
// 			continue ;
// 		}
// 		add_history(str);
// 		if (!parsing(str))
// 		{
// 			lstclear_exec();
// 			continue ;
// 		}
// 		main_execution();
// 		lstclear_exec();
// 	}
// }

/********************      main for tester         ********************/

char	*get_next_line(int fd);
char	*ft_strtrim(const char *s1, const char *set);

int	main(int argc, char const *argv[], char **env)
{
	char	*str;

	(void)argv;
	(void)argc;
	create_env_and_handle_signals(env);
	while (1)
	{
		str = readline("Minishell $>: ");
		if (!str)
			handle_ctr_d(str);
		if (!*str)
		{
			free(str);
			continue ;
		}
		add_history(str);
		if (!parsing(str))
		{
			lstclear_exec();
			continue ;
		}
		main_execution();
		lstclear_exec();
	}
}

char	*get_next_line(int fd)
{
	char	*line;
	char	buf;
	int		i;
	int		size;
	char	*tmp;

	line = NULL;
	i = 0;
	size = 1024;
	line = malloc(size);
	if (!line)
		return (NULL);
	while (read(fd, &buf, 1) > 0)
	{
		line[i++] = buf;
		if (buf == '\n')
			break ;
		if (i >= size - 1)
		{
			size *= 2;
			tmp = malloc(size);
			if (!tmp)
				return (free(line), NULL);
			for (int j = 0; j < i; j++)
				tmp[j] = line[j];
			free(line);
			line = tmp;
		}
	}
	line[i] = '\0';
	if (i == 0)
		return (free(line), NULL);
	return (line);
}
