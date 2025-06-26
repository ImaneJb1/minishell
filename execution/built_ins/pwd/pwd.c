/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 22:50:27 by ijoubair          #+#    #+#             */
/*   Updated: 2025/06/26 16:08:00 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built_in.h"

void	pwd(t_exec *node)
{
	char	cwd[PATH_MAX];
	char *pwd;

	(void)node;
	update_exit_status(0);
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		print_msg_to_fd(cwd, "\n", NULL, 1);
	else	
	{
		pwd = get_value_from_env("PWD");
		if(pwd)
			write(node->fd_out, pwd, ft_strlen(pwd));
		else
		{
			update_exit_status(1);
			perror("minishell :");
		}
	}
}
