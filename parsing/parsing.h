/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:28:39 by imeslaki          #+#    #+#             */
/*   Updated: 2025/04/17 16:36:28 by imeslaki         ###   ########.fr       */
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
// typedef enum s_type
// {
// 	PIPE = 1,
// 	FILE = 2,
// 	CMD = 4,
// 	HERE_DOC = 8,
// 	REDIRECTION_IN = 16,
// 	REDIRECTION_OUT = 32,
// 	APPEND_REDIRECTION = 64,
// 	WORD = 128
// }					t_type;
// tokens struct
// typedef struct s_tokens
// {
// 	char			*input;
// 	t_type			type;
// }					t_tokens;

// enum struct

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
	// t_type			type;
	t_pipe			*pipe;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}					t_cmd;

// 	globale
t_cmd				**v_cmd(void);
t_pipe				*v_pipe(void);

// helper
char				*ft_strchr(const char *str, int c);
size_t				ft_strlen(const char *str);
int					ft_strcmp(const char *s1, const char *s2);
char				*join_str_char(char *str, char c);

// 	linked list functions
t_cmd				*new_node(char *value);
void				lstadd_back(t_cmd **lst, t_cmd *new);
void				lstadd_front(t_cmd **lst, t_cmd *new);
int					lstsize(t_cmd *lst);
t_cmd				*lstlast(t_cmd *lst);

char				*separat_with_one_space(char *str);

void				add_to_list(char ch, int flag);
void				creat_the_list(char *str);

//		operations

int					is_pipe(char *str, int *i);
int					is_double_quote(char *str, int *i);
int					is_singl_quote(char *str, int *i);
void				protect_singl_quoat(char *str, int *i, int flag);
void				protect_double_quoat(char *str, int *i, int flag);
int					is_arg(char *str, int *i);
int					is_reder_in(char *str, int *i);
int					is_reder_out(char *str, int *i);
int					is_reder_out_append(char *str, int *i);
int					is_heredoc(char *str, int *i);
int					is_var(char *str, int *i);

#endif