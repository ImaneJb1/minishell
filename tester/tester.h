/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:14:20 by imeslaki          #+#    #+#             */
/*   Updated: 2025/04/17 19:33:22 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef tester_H
# define tester_H

# include "Unity-master/src/unity.h"
# include "../parsing/parsing.h"

// typedef struct testes {
//     const char *name;
//     const char *command;
//     const char *expected_cmd;
//     int expected_status;
// } testcase;

void	setUp(void);
void	tearDown(void);
int	    tester(void);

#endif