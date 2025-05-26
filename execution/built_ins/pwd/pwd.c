/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 22:50:27 by ijoubair          #+#    #+#             */
/*   Updated: 2025/05/26 15:45:26 by ijoubair         ###   ########.fr       */
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
		perror("getcwd() error\n");
    exit(0);
}
