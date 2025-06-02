/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 22:50:27 by ijoubair          #+#    #+#             */
/*   Updated: 2025/06/02 13:12:01 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built_in.h"

void	pwd(t_exec *node)
{
	char	cwd[PATH_MAX];

	(void)node;
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		printf("%s\n", cwd);
	else
	{
		update_exit_status(1);
		perror("getcwd() error\n");
	}
}
