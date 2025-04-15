/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:28:39 by imeslaki          #+#    #+#             */
/*   Updated: 2025/04/14 23:17:06 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../garbage_collector/garbage_collector.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
// #include "libft/libft.h"

// enum struct

typedef enum
{
	WORD,
	CMD,
	PIPE,
	REDIRECTION_IN,
	REDIRECTION_OUT,
}					t_type;

// arguments splited struct

typedef struct s_pipe
{
	int				fd_read;
	int				fd_write;
	struct s_pipe	*next;
}					t_pipe;

typedef struct s_cmd
{
	char			*content;
	char			*abs_path;
	char			**full_arg;
	t_type			type;
	t_pipe			*pipe;
	struct s_arg	*next;
	struct s_arg	*prev;
}					t_cmd;

//		global

t_cmd				*v_cmd(void);
t_pipe				*v_pipe(void);

char				*ft_strchr(const char *str, int c);
size_t				ft_strlen(const char *str);

t_cmd				*new_node(char *value, t_type type);
void				lstadd_back(t_cmd **lst, t_cmd *new);
void				lstadd_front(t_cmd **lst, t_cmd *new);
int					lstsize(t_cmd *lst);

//		check_function(separate)

char				*separat_with_one_space(char *str);
int					is_arg(char *str, int *i);
int					is_pipe(char *str, int *i);
int					is_singl_quoat(char *str, int *i);
int					is_singl_quoat(char *str, int *i);
int					is_double_quoat(char *str, int *i);
int					is_reder_in(char *str, int *i);
int					is_reder_out(char *str, int *i);
int					is_reder_out_append(char *str, int *i);
int					is_heredoc(char *str, int *i);
int					is_var(char *str, int *i);

#endif