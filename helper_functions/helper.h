/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 01:42:47 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/21 10:45:43 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_H
# define HELPER_H

# include "../garbage_collector/garbage_collector.h"
# include "../minishell.h"

int		ft_strnstr(char *haystack, char *needle);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*insert_str_str(char *str, char *insert, int index);
char	*del_str_len(char *str, size_t start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*insert_char_str(char *str, char ch, int i);
int		ft_strcmp(char *s1, char *s2);
char	*del_char_str_index(char *str, int i);
char	*del_str_str(char *str, char *del);
int	    strlen_2d_array(char **ptr);
char	*separat_with_one_space(char *str);
char	*ft_strchr(char *str, int c);
char	*join_str_char(char *str, char c);
size_t	ft_strlen(char *str);
char	*ft_strdup(char *s1);
int		is_alpha(int c);
int		is_digit(int n);
void	skip_space(char *str, int *i);

#endif