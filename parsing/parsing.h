/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:28:39 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/27 17:09:48 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../linked_list_function/linked_list.h"
# include "../minishell.h"

//      main parsing fuctions

void		remove_quotes(void);

//      fill exec list
void		creat_the_cmd_list(char *line);
void		add_to_cmd_list(char ch, int flag);
char		*unquoted_one_cmd(char *str);

//      fill exec list path
void				fill_path(t_exec *cmd);
int		fill_the_exec_struct(void);
t_exec		*add_to_exec_list(char *str, t_exec *cur, int flag);
void		fill_cmd(t_cmd *token, t_exec **cmd);
int			count_args(t_cmd *cmd);
void		fill_args(t_cmd *token, t_exec **cmd);

// t_exec				   *check_cmd(t_cmd **cmd, t_exec *list);

//		operations functions
void		is_pipe(char *str, int *i);
void		is_double_quote(char *str, int *i);
void		is_singl_quote(char *str, int *i);
void		protect_singl_quotes(char *str, int *i);
void		protect_double_quotes(char *str, int *i);
void		is_arg(char *str, int *i);
void		is_redir_in(char *str, int *i);
void		is_redir_out(char *str, int *i);
void		is_redir_out_append(char *str, int *i);
void		is_heredoc(char *str, int *i);
void		is_var(char *str, int *i);

//		enums helpers functions
bool		is_path(char *str);
bool		is_double_q(char *str);
bool		is_single_q(char *str);
bool		is_cmd_arg(char *str);

//		enums functions
void		identify_all_types(void);
void		identify_symbols(void);
void		identify_cmd(void);
void		identify_file(void);
void		identify_path(void);
void		identify_double_q(void);
void		identify_single_q(void);
void		identify_cmd_arg(void);
void		hanlde_case(void);
void		identify_var(void);
void		identify_delimiter(void);
t_tokens	*init_token_array(void);

//		environment functions
void		expand_variable_value(void);
int			is_valid(char c);
void		change_var_value(t_cmd *cur);
char		*inside_quote(char *command, char *content, int *i, char c);
int			is_var_inside_quote(char *c, int i, int j);
int			check_double_quote(char c, int j);
char		*get_value_from_env(char *key);
void		field_spliting(void);

// 		syntax error
bool		is_valid_syntax(void);
int			check_unclosed_quotes(t_cmd *ptr);
int			check_pipe_syntax(t_cmd *ptr);
int			if_special_at_end(t_cmd *ptr);
int			redir_errors(t_cmd *ptr);
bool		is_special_token(int type);
int			unexpected_token(t_cmd *ptr);
int			here_doc_error(t_cmd *ptr);
t_tokens	*init_redir_array(void);

// error printers
void		print_error_with_token(char *message, char *token);
void		print_error(char *s);
void		print_cmd_error(char *command, char *message);
void		print_error_with_token(char *message, char *token);

//      redirections
void		open_fd_in(t_cmd *token, int *fd);
void		open_fd_out(t_cmd *token, int *fd);
void		open_fd_app(t_cmd *token, int *fd);
void		fill_fds_into_exec(t_cmd *token, t_exec **node);

//      open_fd_heredoc
void		open_fd_heredoc(t_cmd *token, int *fd);
void		write_in_here_doc_file(t_cmd *del, t_data *info, int *fd);
void		get_delimiter(t_cmd **cmd);
void		check_expand_and_put_in_file(t_data *data, int fd);
char		*expand_string(char *string, char *str, int *i);
char		*expand_here_doc_value(char *str, int *i);

#endif