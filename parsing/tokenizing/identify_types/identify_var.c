#include "../../parsing.h"

bool	is_dollar_sign(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			if (str[i + 1] && str[i + 1] != ' ')
				return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

void	identify_var(void)
{
	t_cmd	*ptr;

	ptr = *v_cmd();
	while (ptr)
	{
		if (is_dollar_sign(ptr->content))
			ptr->type |= VARIABLE;
		ptr = ptr->next;
	}
}
