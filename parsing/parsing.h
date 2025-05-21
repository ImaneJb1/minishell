/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:28:39 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/21 10:49:43 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../linked_list_function/linked_list.h"
# include "../minishell.h"



//      main parsing fuctions
int				    parsing(char *str);
void	            creat_the_cmd_list(char *line);
bool				is_valid_syntax(void);
void	            expand_variable_value(void);
void    		    remove_quotes(void);


void				add_to_cmd_list(char ch, int flag);
void                change_the_correct_del(void);
char                *handle_one_cmd(char *str);

//      fill exec list
void                fill_the_exec_struct(void);
t_exec	            *add_to_exec_list(char *str, t_exec *cur, int flag);
// t_exec	            *check_cmd(t_cmd **cmd, t_exec *list);

//		operations functions
void				is_pipe(char *str, int *i);
void				is_double_quote(char *str, int *i);
void				is_singl_quote(char *str, int *i);
void				protect_singl_quotes(char *str, int *i);
void				protect_double_quotes(char *str, int *i);
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
char	            *inside_quote(char *command, char *content, int *i, char c);
int					is_var_inside_quote(char *c, int i, int j);
int					check_double_quote(char c, int j);
char				*get_value_from_env(char *key);
void	field_spliting(void);

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
t_tokens            *init_redir_array(void);
int                 here_doc_error(t_cmd *ptr);
//      redirections
void   open_fd_in(t_cmd *token, int *fd);
void    open_fd_out(t_cmd *token, int *fd);
void    open_fd_app(t_cmd *token, int *fd);
void    fill_fds(t_cmd *token, t_exec **node);

#endif