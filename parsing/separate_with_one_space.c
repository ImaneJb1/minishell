#include "parsing.h"

void	skip_space(char *str, int *i)
{
	if (!str[*i])
		return ;
	while (str[*i] && ft_strchr(" \t", str[*i]))
		(*i)++;
}

int	is_one_space(char *str, int i)
{
	return ((!ft_strchr(" \t", str[i])) || (str[i + 1] && ft_strchr(" \t",
		str[i]) && !ft_strchr(" \t", str[i + 1])));
}

char	*separat_with_one_space(char *str)
{
	int (i),(j) = 0;
	char	*string;
	char	ch;

	i = 0;
	string = ft_malloc(ft_strlen(str) + 1);
	skip_space(str, (&i));
	while (str[i])
	{
		if(ft_strchr("\"\'", str[i]))
		{
			ch = str[i];
			string[j++] = str[i++];
			while(str[i] && str[i] != ch)
				string[j++] = str[i++];
			string[j++] = str[i];
		}
		else if (is_one_space(str, i))
		{
			if (str[i] == '\t')
				string[j] = ' ';
			else
				string[j] = str[i];
			j++;
		}
		i++;
	}
	return (string);
}

// void	add_pipe_to_list(char ch, int flag)
// {
// 	if(flag)
// 	{
// 		t_cmd *node = new_node("|",PIPE);
// 		lstadd_back(v_cmd(), node);
// 	}
// }

// // void	add_arg_to_list(char ch, int flag)
// // {
// // 	static char *word;
// // 	if(flag)
// // 	{
// // 		while()
// // 		t_cmd *node = new_node("|",PIPE);
// // 		lstadd_back(v_cmd(), node);
// // 	}
// // }

// int	is_pipe(char *str, int *i)
// {
// 	if(str[*i] == '|')
// 	{

// 	}
// }

// char	**super_split(char const *s, char c)
// {
// 	char	**ptr;

// 	int (i), (j), (flag);
// 	flag = 0;
// 	i = 0;
// 	j = 0;
// 	ptr = malloc(sizeof(char *) * (super_count(s, c) + 1));
// 	if (!ptr)
// 		return (NULL);
// 	while (s && s[i])
// 	{
// 		c = check_flag(&flag, &i, s);
// 		while (s[i] == c)
// 			i++;
// 		if (s[i] == '\0')
// 			break ;
// 		c = check_flag(&flag, &i, s);
// 		ptr[j] = ft_substr(s, i, super_countlen(s, c, i));
// 		if (ptr[j] == NULL)
// 			return (super_free_2d_arry(ptr));
// 		j++;
// 		while (s[i] && s[i] != c)
// 			i++;
// 	}
// 	return ((ptr[j] = NULL), ptr);
// }

// int	is_sep(char	*str)
// {
// 	if(*str == '|')
// 		return (1);
// 	else if(*str == '$')
// 		return (1);
// 	else if(*str == '<')
// 		return (1);
// 	else if(*str == '>')
// 		return (1);
// 	else if(ft_strchr("<<",*str))
// 		return (2);
// 	else if(ft_strchr(">>",*str))
// 		return (2);

// }
// printf("-%s-\n",sparate_with_one_space("    echo \"hello\"gg  | cat
// 			-e | cat > file "));
// int	count_tokens(char *str)
// {
// 	int		flag;
// 	int		count;
// 	char	current_sep;

// 	flag = 1;
// 	count = 0;
// 	current_sep = '\0';
// 	while (*str)
// 	{
// 		while (*str && !ft_strchr("|$<>\"", *str))
// 		{
// 			printf("%c", *str);
// 			str++;
// 			if (current_sep != '\"' && *str == ' ' && !ft_strchr("|$<>\"", (*str
// 					+ 1)))
// 			{
// 				count++;
// 				printf("\n");
// 			}
// 			else if (current_sep == '\"')
// 			{
// 				while (*str && *str != '\"')
// 				{
// 					printf("%c", *str);
// 					str++;
// 				}
// 			}
// 			// count++;
// 			// printf("here 2\n");
// 		}
// 		if (*str && ft_strchr("|$<>\"", *str))
// 		{
// 			if (*str == '>' && *(str + 1) == '>')
// 			{
// 				printf("%c", *str);
// 				str++;
// 			}
// 			if (*str == '<' && *(str + 1) == '<')
// 			{
// 				printf("%c", *str);
// 				str++;
// 			}
// 			count++;
// 			printf("\n");
// 			current_sep = *str;
// 		}
// 		printf("%c", *str);
// 		str++;
// 	}
// 	return (count);
// }

// void	lexing(char	*str, char	*sep, char	*special_sep)
// {
// 	char	*string;
// 	char	*token;

// 	string = separat_with_one_space(str);
// 	token = ft_malloc(sizeof(char *) * (super_count(s, c) + 1));
// 	if (!token)
// 		return (NULL);
// 	while(*string)
// 	{
// 		if(ft_strchr("|", *string))
// 		{>>

// 		}
// 	}

// }

// int main()
// {
// 	int i = 0;
// 	t_cmd *node;

// 	printf("\n%d\n",count_tokens(separat_with_one_space("echo|hello  > fgg")));
// 	// lexing("    echo \"hello\"  | cat -e | cat > file ", " ", "|<>$");
// }
