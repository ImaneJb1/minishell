#ifndef HEADER_H
# define HEADER_H
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include "parsing.h"

#include "libft/libft.h"
typedef enum 
{
	WORD,
	PIPE,
	REDIRECTION_IN,
	REDIRECTION_OUT,
}t_type;


typedef struct s_struct
{
	char *value;
	t_type type;
	struct s_struct *next;
} t_struct;

#endif