#include "../parsing.h"

void    print_error_with_token(char *message, char *token)
{
    print_error(message);
    write(1, "\'", 2);
    print_error(token);
    write(1, "\'", 2);
    write(1, "\n", 2);
}

void	print_error(char *s)
{
	write(2, s, ft_strlen(s));
}