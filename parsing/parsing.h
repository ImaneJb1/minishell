/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:28:39 by imeslaki          #+#    #+#             */
/*   Updated: 2025/04/27 22:27:53 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../linked_list_function/linked_list.h"
# include "../minishell.h"

// 		tokens struct

// 		pipe struct
// typedef struct s_pipe
// {
// 	int				fd_read;
// 	int				fd_write;
// 	struct s_pipe	*next;
// }					t_pipe;

//		arguments splited struct

// 		environment struct

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
// t_pipe				*v_pipe(void);
t_env				**v_env(void);

void				parsing(char *str);

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
int					is_valid(char c);
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