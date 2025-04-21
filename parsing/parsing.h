/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:28:39 by imeslaki          #+#    #+#             */
/*   Updated: 2025/04/21 02:15:03 by imeslaki         ###   ########.fr       */
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
# include <stdbool.h>
# include "../helper_functions/helper.h"


# ifndef TRUE
#  define TRUE 1
# endif
# ifndef FALSE
#  define FALSE 0
# endif

typedef enum s_type
{
	PIPE = 1 << 0,               // 1
	FILE_NAME = 1 << 1,          // 2
	CMD = 1 << 2,                // 4
	HERE_DOC = 1 << 3,           // 8
	REDIR_IN = 1 << 4,           // 16
	REDIR_OUT = 1 << 5,          // 32
	APPEND_REDIRECTION = 1 << 6, // 64
	WORD = 1 << 7,               // 128
	DOUBLE_Q = 1 << 8,           // 256
	SINGLE_Q = 1 << 9,           // 512
	CMD_ARG = 1 << 10,           // 1024
	PATH = 1 << 11,
	VARIABLE = 1 << 12
}					t_type;

typedef struct s_tokens
{
	char			*input;
	t_type			type;
}					t_tokens;

typedef struct s_pipe
{
	int				fd_read;
	int				fd_write;
	struct s_pipe	*next;
}					t_pipe;

//		arguments splited struct
typedef struct s_cmd
{
	char			*content;
	char			*abs_path;
	char			**full_arg;
	t_type			type;
	t_pipe			*pipe;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}					t_cmd;

//		globale
t_cmd				**v_cmd(void);
t_pipe				*v_pipe(void);


//		linked list functions
t_cmd				*new_node(char *value);
void				lstadd_back(t_cmd **lst, t_cmd *new);
void				lstadd_front(t_cmd **lst, t_cmd *new);
int					lstsize(t_cmd *lst);
t_cmd				*lstlast(t_cmd *lst);

void				add_to_list(char ch, int flag);
void				creat_the_list(char *str);

//		operations
void					is_pipe(char *str, int *i);
void					is_double_quote(char *str, int *i);
void					is_singl_quote(char *str, int *i);
void					protect_singl_quoat(char *str, int *i, int flag);
void					protect_double_quoat(char *str, int *i, int flag);
void					is_arg(char *str, int *i);
void					is_redir_in(char *str, int *i);
void					is_redir_out(char *str, int *i);
void					is_redir_out_append(char *str, int *i);
void					is_heredoc(char *str, int *i);
void					is_var(char *str, int *i);

//		enums helpers
bool				is_path(char *str);
bool				is_double_q(char *str);
bool				is_single_q(char *str);
bool				is_cmd_arg(char *str);

//		enums
void				identify_all_types(void);
void				identify_symbols(void);
void				identify_cmd(void);
void				identify_file(void);
void				identify_path(void);
void				identify_double_q(void);
void				identify_single_q(void);
void				identify_cmd_arg(void);
void				hanlde_case(void);
void				identify_var(void);
t_tokens			*init_token_array(void);



#endif