/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 01:42:47 by imeslaki          #+#    #+#             */
/*   Updated: 2025/04/24 17:48:18 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_H
# define HELPER_H

# include "../garbage_collector/garbage_collector.h"
# include <stdlib.h>

int		ft_strnstr(const char *haystack, const char *needle);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*insert_str_str(char *str, char *insert, int index);
char	*del_str_len(char *str, int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*insert_char_str(char *str, char ch, int i);
int		ft_strcmp(const char *s1, const char *s2);
char	*del_char_str_index(char *str, int i);
char	*del_str_str(char *str, char *del);
char	*separat_with_one_space(char *str);
char	*ft_strchr(const char *str, int c);
char	*join_str_char(char *str, char c);
size_t	ft_strlen(const char *str);
char	*ft_strdup(char *s1);

#endif