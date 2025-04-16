/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 23:35:37 by imeslaki          #+#    #+#             */
/*   Updated: 2025/04/16 23:37:50 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

// #include "parsing.h"
// 	globale
t_cmd				**v_cmd(void);
t_pipe				*v_pipe(void);

// helper
char				*ft_strchr(const char *str, int c);
size_t				ft_strlen(const char *str);
int					ft_strcmp(const char *s1, const char *s2);
char				*join_str_char(char *str, char c);

#endif