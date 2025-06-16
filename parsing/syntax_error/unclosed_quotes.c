#include "../parsing.h"

int	check_unclosed_quotes(t_cmd *ptr)
{
	int		i;
	char	quote;
	char	*str;

	str = ptr->content;
	quote = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
		{
			if (quote == 0)
				quote = str[i];
			else if (quote == str[i])
				quote = 0;
		}
		i++;
	}
	if (quote != 0)
		print_error("Syntax error unclosed quotes\n");
	return (quote);
}
