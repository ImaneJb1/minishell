/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imane <imane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:28:39 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/25 11:16:37 by imane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../linked_list_function/linked_list.h"
# include "../minishell.h"

int			this_is_i(int set, int value);
t_data		*init_data(void);
void		remove_quotes(void);

//      check_functions
int			not_first_cmd(int flag);
int			inside_child(int flag);
int			heredoc_exit_with_signal(int flag);

//      fill exec list
void		creat_the_cmd_list(char *line);
void		add_to_cmd_list(char ch, int flag);
char		*unquoted_one_cmd(char *str);

//      fill exec list path
void		fill_path(t_exec *cmd);
int			fill_the_exec_struct(void);
t_exec		*add_to_exec_list(char *str, t_exec *cur, int flag);
void		fill_cmd(t_cmd *token, t_exec **cmd);
int			count_args(t_cmd *cmd);
void		fill_args(t_cmd *token, t_exec **cmd);

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
char		*add_var_string(char *command, t_cmd *cur, int *i, int x);
char		*expand_the_value(char *command, t_data *data);
void		field_spliting(void);
int			is_not_field(char *content);
int			len_of_word(char *str, int j);
void		skip_quotes(char *str, int *i);
int			field_count_arg(int flag);

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
void		print_error_token(char *message, char *token);
//      error printers
void		print_error(char *s);
void		print_cmd_error(char *command, char *message);
void		print_error_token(char *message, char *token);

//      redirections
void		open_fd_in(t_cmd *token, int *fd);
int		open_fd_out(t_cmd *token, t_exec **node);
int		open_fd_app(t_cmd *token, t_exec **node);
void		fill_fds_into_exec(t_cmd *token, t_exec **node);
int			is_redirection(t_cmd *cur);
int			check_redir(t_cmd *cur, t_type type1, t_type type2);
// int			is_ambiguous(t_cmd *cur);

//      open_fd_heredoc
void		open_fd_heredoc(t_cmd *token, int *fd);
void		write_in_here_doc_file(t_cmd *del, t_data *info, int *fd);
void		get_delimiter(t_cmd **cmd);
void		check_expand_and_put_in_file(t_data *data, int fd);
char		*expand_heredoc_string(char *string, char *str, int *i);
char		*expand_here_doc_value(char *str, int *i);
int			count_heredoc(int flag);

// fill fd arr
void		fill_fdout_arr(t_exec *node);
#endif