/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:28:39 by imeslaki          #+#    #+#             */
/*   Updated: 2025/04/16 23:38:12 by imeslaki         ###   ########.fr       */
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
# include "../globale_functions/global.h"
# ifndef TRUE
#  define TRUE 1
# endif
# ifndef FALSE
#  define FALSE 0
# endif
typedef enum s_type
{
	PIPE                = 1 << 0,  // 1
	FILE                = 1 << 1,  // 2
	CMD                 = 1 << 2,  // 4
	HERE_DOC            = 1 << 3,  // 8
	REDIR_IN      = 1 << 4,  // 16
	REDIR_OUT     = 1 << 5,  // 32
	APPEND_REDIRECTION  = 1 << 6,  // 64
	WORD                = 1 << 7,  // 128
	DOUBLE_Q            = 1 << 8,  // 256
	SINGLE_A            = 1 << 9   // 512
	CMD_ARG				= 1 << 10 // 1024
} t_type;

typedef struct s_tokens
{
	char			*input;
	t_type			type;
}					t_tokens;

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
	t_type			type;
	t_pipe			*pipe;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}					t_cmd;

// // 	globale
// t_cmd				**v_cmd(void);
// t_pipe				*v_pipe(void);

// // helper
// char				*ft_strchr(const char *str, int c);
// size_t				ft_strlen(const char *str);
// int					ft_strcmp(const char *s1, const char *s2);
// char				*join_str_char(char *str, char c);

// 	linked list functions
t_cmd				*new_node(char *value);
void				lstadd_back(t_cmd **lst, t_cmd *new);
void				lstadd_front(t_cmd **lst, t_cmd *new);
int					lstsize(t_cmd *lst);
t_cmd				*lstlast(t_cmd *lst);

char				*separat_with_one_space(char *str);

void				add_to_list(char ch, int flag);

//		operations

int					is_double_quoat(char *str, int *i);
int					is_singl_quoat(char *str, int *i);

// helpers
bool    is_path(char *str);
bool    is_double_q(char *str);
bool    is_single_q(char *str);
bool    is_cmd_arg(char *str);

#endif