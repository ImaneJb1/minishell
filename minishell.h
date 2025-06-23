/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:29:38 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/18 22:55:12 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./garbage_collector/garbage_collector.h"
# include "./helper_functions/helper.h"
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# ifndef TRUE
#  define TRUE 1
# endif
# ifndef FALSE
#  define FALSE 0
# endif

extern int			g_exit_status;

typedef enum s_type
{
	PIPE = 1 << 0,
	FILE_NAME = 1 << 1,
	CMD = 1 << 2,
	HERE_DOC = 1 << 3,
	REDIR_IN = 1 << 4,
	REDIR_OUT = 1 << 5,
	APPEND = 1 << 6,
	WORD = 1 << 7,
	DOUBLE_Q = 1 << 8,
	SINGLE_Q = 1 << 9,
	CMD_ARG = 1 << 10,
	PATH = 1 << 11,
	VARIABLE = 1 << 12,
	DELIMITER = 1 << 13,
}					t_type;

typedef struct s_tokens
{
	char			*input;
	t_type			type;
}					t_tokens;

typedef struct s_data
{
	int				i;
	int				j;
	int				x;
	int				pid;
	int				count;
	int				flag;
	int				status;
	int				fd;
	char			c;
	char			*key;
	char			*value;
	char			*word;
	char			*str;
	char			*content;
	char			*command;
	char			*del;
	char			**args;
}					t_data;

typedef struct s_exec
{
	char			*path;
	char			*cmd;
	char			**args;
	int				fd_in;
	int				fd_out;
	struct s_exec	*next;
	struct s_exec	*prev;
}					t_exec;

typedef struct s_cmd
{
	char			*content;
	int				fd_in;
	int				fd_out;
	int				index;
	t_type			type;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}					t_cmd;

typedef enum s_env_type
{
	global,
	local,
	special
}					t_env_type;

typedef struct s_env
{
	char			*key;
	char			*value;
	int				index;
	t_env_type		type;
	struct s_env	*next;
	struct s_env	*prev;
}					t_env;

int					is_paht_empty(int flag);

//		globale
t_cmd				**v_cmd(void);
t_exec				**v_exec(void);
t_env				**v_env(void);

// 		errors and exit
int					is_error(int flag);
int					handle_exec_error(void);
void				print_msg_to_fd(char *s1, char *s2, char *s3, int fd);
void				free_exit(int status);
void				print_execve_errors(t_exec *cmd);
int					fd_error(t_exec *cmd);

// 		parsing function
int					parsing(char *str);
void				create_environment(char **env);

// 		execution functions
void				update_exit_status(int status);
void				main_execution(void);
void				pipes(void);

// 		signels
void				handle_sig_int(int signum);
void				sigint_in_heredoc_child(int num);

// !! REMOVE !!
void				print_parsing(void);

#endif