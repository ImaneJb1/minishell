#include "../parsing.h"

static int	is_ambiguous__redir_appand(t_cmd *cur)
{
	if ((cur->prev && (cur->prev->type & APPEND)) && !(cur->type & FILE_NAME))
		return (1);
	else if ((cur->type & FILE_NAME) && (cur->prev
				&& (cur->prev->type & APPEND)))
	{
		if (field_count_arg(2) > 1)
			return (1);
	}
	return (0);
}

bool	if_its_appfile(t_cmd *ptr)
{
	if (is_ambiguous__redir_appand(ptr))
	{
		is_error(1);
		ft_putstr_fd("bash: ambiguous redirect\n", STDERR_FILENO);
		return (FALSE);
	}
	if ((ptr->type & FILE_NAME) && (ptr->prev && (ptr->prev->type & APPEND)))
		return (TRUE);
	return (FALSE);
}

void	open_fd_app(t_cmd *token, int *fd)
{
	if (if_its_appfile(token))
	{
		*fd = open(token->content, O_RDWR | O_CREAT | O_APPEND, 0666);
		if (*fd < 0)
			perror(token->content);
	}
}
