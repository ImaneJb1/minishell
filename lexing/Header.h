#ifndef HEADER_H
# define HEADER_H
# include "../libft/libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
typedef enum
{
	WORD,
	PIPE,
	REDIRECTION_IN,
	REDIRECTION_OUT,
}					t_type;

typedef struct s_struct
{
	char			*value;
	t_type			type;
	struct s_struct	*next;
}					t_struct;

// 		split_functions

size_t				ft_strlen(const char *str);
char				**super_split(char const *s, char c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					super_count(char const *s, char c);
size_t				super_countlen(char const *s, char c, size_t i);
void				*super_free_2d_arry(char **ptr);
int					super_check(char const *str);

#endif