/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:16:03 by imeslaki          #+#    #+#             */
/*   Updated: 2025/04/14 00:34:28 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "test.h"

// t_struct    *linked_list(t_struct *list)
// {
//     t_struct *cmd1 = new_node("echo", CMD);
//     t_struct *cmd2 = new_node("hello", WORD);
//     t_struct *cmd3 = new_node("|", PIPE);
//     t_struct *cmd4 = new_node("ls", CMD);
//     lstadd_back(&list,cmd1);
//     lstadd_back(&list,cmd2);
//     lstadd_back(&list,cmd3);
//     lstadd_back(&list,cmd4);
//     return list;
// }
// // echo  hello |  ls

// char    *check_pipe(t_struct *list)
// {
//     t_struct *head = list;
//     while(list)
//     {
//         if(list->type == PIPE)
        
//         list = list->next;
//     }
// }

// int main(int argc, char const *argv[])
// {
//     t_struct *list;
//     list = NULL;
//     list = linked_list(list);
//     check_pipe(list);
//     t_struct *head = list;
//     while((head))
//     {
//         printf("%s\n",(head)->value);
//         head = (head)->next;
//     }
// }
