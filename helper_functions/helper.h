/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 01:42:47 by imeslaki          #+#    #+#             */
/*   Updated: 2025/04/21 02:16:38 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_H
# define HELPER_H

# include "../garbage_collector/garbage_collector.h"
# include <stdlib.h>

char	*separat_with_one_space(char *str);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
char	*join_str_char(char *str, char c);


#endif