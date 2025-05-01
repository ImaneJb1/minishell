/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 02:09:47 by imeslaki          #+#    #+#             */
/*   Updated: 2025/04/30 18:15:42 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "../tester/tester.h"
#include "../built_ins/built_in.h"



int    parsing(char *str)
{
    creat_the_list(str);
    identify_all_types();
    if(is_valid_syntax() == FALSE)
        return (lstclear_cmd(), 1);
    environment_variable_value();
    remove_quotes();
    return 1;
}

