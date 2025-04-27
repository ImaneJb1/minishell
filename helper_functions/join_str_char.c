#include "helper.h"

char	*join_str_char(char *str, char c)
{
	char	*result;
	int		i;

	if (str == NULL)
	{
		result = ft_malloc(2);
		if (!result)
			return (NULL);
		result[0] = c;
		result[1] = 0;
		return (result);
	}
	result = ft_malloc(ft_strlen(str) + 2);
	if (!result)
		return (NULL);
	i = 0;
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[i] = c;
	result[i + 1] = 0;
	return (result);
}
