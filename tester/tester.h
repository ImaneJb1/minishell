/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:14:20 by imeslaki          #+#    #+#             */
/*   Updated: 2025/04/21 14:48:38 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_H
# define TESTER_H

# include "../parsing/parsing.h"
# include "Unity-master/src/unity.h"

#define COUNT(a) (sizeof(a) / sizeof(a[0]))

typedef struct s_cases
{
	const char		*command;
	t_type			type;
	struct s_cases	*next;
}					t_case;

void				setUp(void);
void				tearDown(void);
int					tester(void);

#endif