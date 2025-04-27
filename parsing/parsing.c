/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 02:09:47 by imeslaki          #+#    #+#             */
/*   Updated: 2025/04/27 22:36:00 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "../tester/tester.h"



void    parsing(char *str)
{
    creat_the_list(str);
    identify_all_types();
    if(is_valid_syntax() == FALSE)
        return;
    environment_variable_value();
    
}

