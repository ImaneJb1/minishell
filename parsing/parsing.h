/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:28:39 by imeslaki          #+#    #+#             */
/*   Updated: 2025/04/27 17:44:29 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../garbage_collector/garbage_collector.h"
# include "../helper_functions/helper.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef TRUE
#  define TRUE 1
# endif
# ifndef FALSE
#  define FALSE 0
# endif

// 		enums type
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
	VARIABLE = 1 << 12,
	DELIMITER = 1 << 13
}					t_type;
// 		tokens struct
typedef struct s_tokens
{
	char			*input;
	t_type			type;
}					t_tokens;

// 		pipe struct
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
	int				index;
	t_type			type;
	t_pipe			*pipe;
	struct s_cmd	*next;

	struct s_cmd	*prev;
}					t_cmd;

// 		environment struct
typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

// r

// execute struct
typedef struct s_exec
{
	char			*abs_path;
	char			**cmd;
	int				fd_in;
	int				fd_out;
	struct s_exec	*next;
	struct s_exec	*prev;
}					t_exec;

//		globale
t_cmd				**v_cmd(void);
t_pipe				*v_pipe(void);
t_env				**v_env(void);

//		linked list functions
void				index_the_cmd_list(void);
t_cmd				*lst_new_cmd_node(char *value);
void				lstadd_cmd_back(t_cmd **lst, t_cmd *new);
void				lstadd_cmd_front(t_cmd **lst, t_cmd *new);
t_cmd				*find_cmd_by_index(int index);
int					lstsize_cmd(t_cmd *lst);
t_cmd				*lstlast_cmd(t_cmd *lst);
void				lstclear_cmd(void);
void				lst_del_one_cmd(int index);
void				lst_add_one_cmd(t_cmd *new, int index);
t_env				*new_env_node(char *key, char *value);
void				lstadd_env_back(t_env **lst, t_env *new);
void				lstadd_env_front(t_env **lst, t_env *new);
t_env				*lstlast_env(t_env *lst);
int					lstsize_env(t_env *lst);

// 		spliting functions
void				add_to_list(char ch, int flag);
void				creat_the_list(char *str);

//		operations functions
void				is_pipe(char *str, int *i);
void				is_double_quote(char *str, int *i);
void				is_singl_quote(char *str, int *i);
void				protect_singl_quoat(char *str, int *i);
void				protect_double_quoat(char *str, int *i);
void				is_arg(char *str, int *i);
void				is_redir_in(char *str, int *i);
void				is_redir_out(char *str, int *i);
void				is_redir_out_append(char *str, int *i);
void				is_heredoc(char *str, int *i);
void				is_var(char *str, int *i);

//		enums helpers functions
bool				is_path(char *str);
bool				is_double_q(char *str);
bool				is_single_q(char *str);
bool				is_cmd_arg(char *str);

//		enums functions
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
void				identify_delimiter(void);
t_tokens			*init_token_array(void);

//		environment functions
void				creat_environment(char **env);
void				change_var_value(t_cmd *cur);
void				environment_variable_value(void);
char				*inside_singl_quote(char *command, char *content, int *i);
int					is_var_inside_quote(char *c, int i, int j);
int					check_double_quote(char c, int j);
char				*get_value_from_env(char *key);

// 		syntax error
int					check_unclosed_quotes(t_cmd *ptr);
int					check_pipe_syntax(t_cmd *ptr);
void				print_error(char *s);
int					if_special_at_end(t_cmd *ptr);
int					redir_errors(t_cmd *ptr);
bool				is_special_token(int type);
void				print_error_with_token(char *message, char *token);
int					unexpected_token(t_cmd *ptr);
void				print_error_with_token(char *message, char *token);
bool				is_valid_syntax(void);

#endif