/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:29:38 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/28 15:21:40 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./garbage_collector/garbage_collector.h"
# include "./helper_functions/helper.h"
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
// # include "execution/execution.h" 
// # include "./parsing/parsing.h"
extern int exit_status;

# ifndef TRUE
#  define TRUE 1
# endif
# ifndef FALSE
#  define FALSE 0
# endif

// 		enums type
typedef enum s_type
{
	PIPE = 1 << 0,      // 1
	FILE_NAME = 1 << 1, // 2
	CMD = 1 << 2,       // 4
	HERE_DOC = 1 << 3,  // 8
	REDIR_IN = 1 << 4,  // 16
	REDIR_OUT = 1 << 5, // 32
	APPEND = 1 << 6,    // 64
	WORD = 1 << 7,      // 128
	DOUBLE_Q = 1 << 8,  // 256
	SINGLE_Q = 1 << 9,  // 512
	CMD_ARG = 1 << 10,  // 1024
	PATH = 1 << 11,
	VARIABLE = 1 << 12,
	DELIMITER = 1 << 13
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

typedef struct s_pipe
{
	int				write;
	int				read;
	int				index;
	struct s_pipe	*next;
	struct s_pipe	*prev;
}					t_pipe;

// typedef enum s_execute_type
// {
// 	builtin_cmd,
// 	non_builtin_cmd
// }	t_execute_type;

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
}	t_env_type;

typedef struct s_env
{
	char			*key;
	char			*value;
	int				index;
	t_env_type		type;
	struct s_env	*next;
	struct s_env	*prev;
}					t_env;



void	main_execution(void);
int		pipes(void);

void				print_parsing(void);

//		globale
t_cmd				**v_cmd(void);
t_exec				**v_exec(void);
t_pipe				**v_pipe(void);
t_env				**v_env(void);

t_data				*init_data(void);
// void				add_to_exec_list(char *str, t_exec *cur, int flag);
int					parsing(char *str);
void				create_environment(char **env);

#endif