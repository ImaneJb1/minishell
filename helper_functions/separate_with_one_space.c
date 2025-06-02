#include "helper.h"

void	skip_space(char *str, int *i)
{
	if (!str)
		return ;
	while (str[*i] && ft_strchr(" \t", str[*i]))
		(*i)++;
}

int	is_one_space(char *str, int i)
{
	return ((!ft_strchr(" \t", str[i])) || (str[i + 1] && ft_strchr(" \t",
				str[i]) && !ft_strchr(" \t", str[i + 1])));
}

void	add_to_string(char *str, int *i, char *string, int *j)
{
	if (is_one_space(str, *i))
	{
		if (str[*i] == '\t')
			string[*j] = ' ';
		else
			string[*j] = str[*i];
		(*j)++;
	}
}

char	*separat_with_one_space(char *str)
{
	char	*string;
	char	ch;

	int(i), (j) = 0;
	i = 0;
	string = ft_malloc(ft_strlen(str) + 1);
	skip_space(str, (&i));
	while (str && str[i])
	{
		if (ft_strchr("\"\'", str[i]))
		{
			ch = str[i];
			string[j++] = str[i++];
			while (str[i] && str[i] != ch)
				string[j++] = str[i++];
			if (str[i] == ch)
				string[j++] = str[i];
			else
				break ;
		}
		else
			add_to_string(str, &i, string, &j);
		i++;
	}
	return (string);
}
