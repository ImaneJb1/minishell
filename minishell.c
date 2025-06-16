/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:31:31 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/16 15:24:35 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parsing/parsing.h"
#include "execution/built_ins/built_in.h"
#include "minishell.h"

int		g_exit_status;

void	print_parsing(void)
{
	t_cmd	*ptr;

	ptr = *v_cmd();
	printf("----------------------------------------------\n");
	printf("                    PARSING                   \n");
	printf("----------------------------------------------\n");
	while (ptr)
	{
		printf("[%s] = ", ptr->content);
		if (ptr->type & WORD)
			printf("WORD ");
		if (ptr->type & FIELD)
			printf("FIELD ");
		if (ptr->type & FILE_NAME)
			printf("FILE_NAME ");
		if (ptr->type & CMD)
			printf("CMD ");
		if (ptr->type & CMD_ARG)
			printf("CMD_ARG ");
		if (ptr->type & DOUBLE_Q)
			printf("DOUBLE_Q ");
		if (ptr->type & SINGLE_Q)
			printf("SINGLE_Q ");
		if (ptr->type & PIPE)
			printf("PIPE ");
		if (ptr->type & HERE_DOC)
			printf("HERE_DOC ");
		if (ptr->type & REDIR_IN)
			printf("REDIR_IN ");
		if (ptr->type & REDIR_OUT)
			printf("REDIR_OUT ");
		if (ptr->type & APPEND)
			printf("APPEND ");
		if (ptr->type & PATH)
			printf("PATH ");
		if (ptr->type & VARIABLE)
			printf("VARIABLE");
		if (ptr->type & DELIMITER)
			printf("DELIMITER");
		printf("  (%d) ", ptr->index);
		ptr = ptr->next;
		printf("\n");
	}
	printf("----------------------------------------------\n");
	printf("----------------------------------------------\n");
}

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
	ft_putstr_fd("exit\n", 1);
	ft_exit(g_exit_status);
}

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

/********************      main for tester         ********************/

char	*get_next_line(int fd);
char	*ft_strtrim(const char *s1, const char *set);

// int	main(int argc, char const *argv[], char **env)
// {
// 	char	*str;

// 	(void)argc;
// 	(void)argv;
// 	create_env_and_handle_signals(env);

// 	while (1)
// 	{
// 		if (isatty(fileno(stdin)))
// 		{
// 			// str = get_next_line(fileno(stdin));
// 			// if (str)
// 			// {
// 			// 	char *trimmed = ft_strtrim(str, "\n");
// 			// 	free(str);
// 			// 	str = trimmed;
// 			// }
// 			str = readline("Minishell $>: ");
// 		}
// 		else
// 		{
// 			str = get_next_line(fileno(stdin));
// 			if (str)
// 			{
// 				char *trimmed = ft_strtrim(str, "\n");
// 				free(str);
// 				str = ft_strdup(trimmed);
// 			}
// 		}
// 		// printf("(%s)\n",str);
// 		if (!str)
// 			handle_ctr_d(str); // Usually should call `exit()` or free & return

// 		if (!*str)
// 		{
// 			free(str);
// 			continue ;
// 		}

// 		if (isatty(fileno(stdin))) // only add to history in interactive mode
// 			add_history(str);

// 		if (!parsing(str))
// 		{
// 			free(str);
// 			lstclear_exec();
// 			continue ;
// 		}

// 		main_execution();
// 		lstclear_exec();
// 		free(str);
// 	}
// }

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

int	is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	end = start;
	while (s1[end])
		end++;
	while (end > start && is_in_set(s1[end - 1], set))
		end--;
	len = end - start;
	trimmed = malloc(len + 1);
	if (!trimmed)
		return (NULL);
	for (size_t i = 0; i < len; i++)
		trimmed[i] = s1[start + i];
	trimmed[len] = '\0';
	return (trimmed);
}
