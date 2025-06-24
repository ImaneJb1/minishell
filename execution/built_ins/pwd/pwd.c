/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 22:50:27 by ijoubair          #+#    #+#             */
/*   Updated: 2025/06/24 14:51:48 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built_in.h"

void	pwd(t_exec *node)
{
	char	cwd[PATH_MAX];
	char *pwd;

	(void)node;
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		printf("%s\n", cwd);
	else	
	{
		pwd = get_value_from_env("PWD");
		if(pwd)
			write(node->fd_out, pwd, ft_strlen(pwd));
		else
		{
			update_exit_status(1);
			perror("");
		}
	}
}
