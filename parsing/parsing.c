/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 02:09:47 by imeslaki          #+#    #+#             */
/*   Updated: 2025/04/21 02:09:48 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "../tester/tester.h"

int main(int argc, char const *argv[])
{
    char *str;
    int i;
    i = 0;
    i = 1;
    if(i == 1)
    {
        i = tester();
        return i;
    }
    str = "echo \"unclosed";
    while(1)
    {
        str = readline("prompt : ");
        // printf("%s\n",str);
        // exit(1);
	    creat_the_list(str);

	    t_cmd *ptr = (*v_cmd());
	    while(ptr)
	    {
	    	printf("%s\n", ptr->content);
	    	ptr = ptr->next;
	    }
    }
}
