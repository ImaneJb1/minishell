#include "../../parsing.h"

void	identify_symbols(void)
{
	t_cmd		*ptr;
	int			i;
	t_tokens	*token;
	int			token_len;

	token = init_token_array();
	token_len = 5;
	ptr = *v_cmd();
	while (ptr)
	{
		i = 0;
		ptr->type = WORD;
		while (i < token_len)
		{
			if (ft_strcmp(ptr->content, token[i].input) == 0)
				ptr->type = token[i].type;
			i++;
		}
		ptr = ptr->next;
	}
}

void	identify_cmd(void)
{
	t_cmd	*ptr;
	int		flag;

	flag = 0;
	ptr = *v_cmd();
	while (ptr)
	{
		if ((ptr->type == WORD || ptr->type & PATH) && flag == 0)
		{
			ptr->type |= CMD;
			flag = 1;
		}
		if (ptr->type == PIPE)
			flag = 0;
		ptr = ptr->next;
	}
}

int	is_redir_type(t_cmd *ptr)
{
	if (ptr->prev->type & REDIR_IN)
		return (1);
	if (ptr->prev->type & REDIR_OUT)
		return (1);
	if (ptr->prev->type & APPEND)
		return (1);
	return (0);
}

void	identify_file(void)
{
	t_cmd	*ptr;

	ptr = *v_cmd();
	ptr = ptr->next;
	while (ptr)
	{
		if (ptr->type & WORD)
		{
			if (is_redir_type(ptr))
				ptr->type = ptr->type | FILE_NAME;
		}
		ptr = ptr->next;
	}
}

void	hanlde_case(void)
{
	t_cmd	*ptr;

	ptr = *v_cmd();
	while (ptr)
	{
		if (ptr->type & FILE_NAME)
		{
			if (ptr->prev && (ptr->prev->type & REDIR_IN))
			{
				if (ptr->next && (ptr->next->type & WORD))
					ptr->next->type |= CMD;
			}
		}
		ptr = ptr->next;
	}
}
