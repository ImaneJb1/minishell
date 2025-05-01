/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:29:38 by imeslaki          #+#    #+#             */
/*   Updated: 2025/04/27 22:34:31 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/history.h>
# include <readline/readline.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "./garbage_collector/garbage_collector.h"
# include "./helper_functions/helper.h"

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

typedef struct s_tokens
{
	char			*input;
	t_type			type;
}					t_tokens;

typedef struct s_cmd
{
	char			*content;
	char			*abs_path;
	char			**full_arg;
	int				index;
	t_type			type;
	// t_pipe			*pipe;
	struct s_cmd	*next;

	struct s_cmd	*prev;
}					t_cmd;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

void				parsing(char *str);
void				create_environment(char **env);

#endif