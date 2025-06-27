/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:31:31 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/26 19:12:21 by imeslaki         ###   ########.fr       */
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
