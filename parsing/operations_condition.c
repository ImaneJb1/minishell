
#include "parsing.h"

int	is_arg(char *str, int *i)
{
	if( !ft_strchr(" \"\'|<>$", str[*i]))
	{
		while (str[*i] && !ft_strchr(" |<>$", str[*i]))
		{
			if(str[*i] == '\'')
				is_singl_quoat(str, i);
			else if(str[*i] == '\"')
				is_double_quoat(str, i);
			else
			{
				add_to_list(str[*i],1);
				(*i)++;
			}
		}
		add_to_list(0,2);
		add_to_list(0,0);
		return 1;
	}
	return 0;
}

int	is_pipe(char *str, int *i)
{
	if (str[*i] == '|')
	{
        add_to_list(str[*i],1);
		add_to_list(0,2);
		add_to_list(0,0);
		(*i)++;
		return 1;
	}
	return 0;
}

void	protect_singl_quoat(char *str, int *i, int flag)
{
	while (str[*i])
	{
		if(( str[*i] != '\'' && flag == 0) || (!ft_strchr(" \"\'|<>$", str[*i]) && flag == 1))
        {
			add_to_list(str[*i],1);
			(*i)++;
		}
		else if (str[*i] == '\'' && !ft_strchr(" |<>$", str[*i + 1]))
		{
			flag = 1;
			add_to_list(str[*i],1);
			(*i)++;
		}
		else
        {
			if(str[*i] == '\'' && ft_strchr(" |<>$", str[*i + 1]))
			{
				add_to_list(str[*i],1);
				(*i)++;
			}
		    break;
		}
	}
}

int	is_singl_quoat(char *str, int *i)
{
	int flag;

	flag = 0;
	if (str[*i] && str[*i] == '\'')
	{
        add_to_list(str[*i],1);
		(*i)++;
		protect_singl_quoat(str, i, flag);
		add_to_list(str[*i],1);
        return 1;
	}
    return 0;
}

void	protect_double_quoat(char *str, int *i, int flag)
{
	while (str[*i])
	{
		if(( str[*i] != '\"' && flag == 0) || (!ft_strchr(" \"\'|<>$", str[*i]) && flag == 1))
        {
			add_to_list(str[*i],1);
			(*i)++;
		}
		else if (str[*i] == '\"' && !ft_strchr(" |<>$", str[*i + 1]))
		{
			flag = 1;
			add_to_list(str[*i],1);
			(*i)++;
		}
		else
        {
			if(str[*i] == '\"' && ft_strchr(" |<>$", str[*i + 1]))
			{
				add_to_list(str[*i],1);
				(*i)++;
			}	
		    break;
		}
	}
}

int	is_double_quoat(char *str, int *i)
{
	int flag;

	flag = 0;
	if (str[*i] == '\"')
	{
        add_to_list(str[*i],1);
		(*i)++;
		protect_double_quoat(str, i, flag);
		add_to_list(0,2);
		add_to_list(0,0);
        return 1;
	}
    return 0;
}

int	is_reder_in(char *str, int *i)
{
	if (str[*i] && str[*i] == '<')
	{
        add_to_list(str[*i],1);
		(*i)++;
		add_to_list(0,2);
		add_to_list(0,0);
		return 1;
	}
	return 0;
}

int	is_reder_out(char *str, int *i)
{
	if (str[*i] && str[*i] == '>')
	{
        add_to_list(str[*i],1);
		(*i)++;
		add_to_list(0,2);
		add_to_list(0,0);
		return 1;
	}
	return 0;
}
//	echo hell >> 
int	is_reder_out_append(char *str, int *i)
{
	if (str[*i] && str[*i + 1] && str[*i] == '>' && str[*i + 1] == '>')
	{
        add_to_list(str[*i],1);
		add_to_list(str[*i + 1],1);
		(*i) += 2;
		add_to_list(0,2);
		add_to_list(0,0);
		// if(str[*i] &&  str[*i] == '>')
		// 	printf("\nError : >>>\n");
		return 1;
	}
	return 0;
}

int	is_heredoc(char *str, int *i)
{
	if (str[*i] && str[*i + 1] && str[*i] == '<' && str[*i + 1] == '<')
	{
        add_to_list(str[*i],1);
		add_to_list(str[*i + 1],1);
		(*i) += 2;
		add_to_list(0,2);
		add_to_list(0,0);
		return 1;
	}
	return 0;
}

int	is_var(char *str, int *i)
{ 
	if ( str[*i] == '$' && ft_strchr(" |<>$", str[*i + 1]))
	{
        add_to_list(str[*i],1);
		(*i)++;
		add_to_list(0,2);
		add_to_list(0,0);
        return 1;
	}
	else if(str[*i] == '$' && !ft_strchr(" |<>$", str[*i + 1]))
	{
		add_to_list(str[*i],1);
		(*i)++;
		while(str[*i] && ft_strchr(" |<>$",str[*i]))
		{
			add_to_list(str[*i],1);
			(*i)++;
		}
	}
    return 0;
}

void all(char *str)
{
    int i = 0;
    while(str[i])
    {
		if(str[i] == ' ')
		{
			i++;
			add_to_list(0,0);
		}
		if(is_arg(str, &i))
            ;
		else if(is_double_quoat(str, &i))
            ;
        else if(is_singl_quoat(str, &i))
            ;
		else if(is_pipe(str, &i))
			;
		else if(is_reder_out_append(str, &i))
			;
		else if(is_heredoc(str, &i))
			;
		else if(is_reder_in(str, &i))
			;
		else if(is_reder_out(str, &i))
			;
		else if(is_var(str, &i))
			;
	}
}

int	main(void)
{
    char *str;

	// str = separat_with_one_space("echo bonjour ; |");
 	// str = separat_with_one_space("echo bonjour | |");
 	// str = separat_with_one_space("|");
 	// str = separat_with_one_space("echo bonjour |;");
 	// str = separat_with_one_space("echo bonjour ; ls");
 	// str = separat_with_one_space("echo bonjour > test\ 1");
 	// str = separat_with_one_space("cd $HOME/Documents");
 	// str = separat_with_one_space("echo \"\s\" & echo \"\s\"");
 	// str = separat_with_one_space("echo >");
 	// str = separat_with_one_space("echo -n -n -nnnn -nnnnm");
 	// str = separat_with_one_space("cat /dev/random | head -n 1 | cat -e");
 	// str = separat_with_one_space("unset var1 # with undefined var1");
 	// str = separat_with_one_space("export "" et unset """);
 	// str = separat_with_one_space("echo test > file test1");
 	// str = separat_with_one_space("$");
 	// str = separat_with_one_space("not_cmd bonjour > salut");
 	// str = separat_with_one_space("env puis export puis env # vars aren't sorted");
 	// str = separat_with_one_space("cat Makefile | grep pr | head -n 5 | cd test (mybin) # check status code");
 	// str = separat_with_one_space("cat Makefile | grep pr | head -n 5 | cat test (bin) # check status code");
 	// str = separat_with_one_space("cat Makefile | grep pr | head -n 5 | hello (NA) # check status code");
 	// str = separat_with_one_space("echo bonjour >>> test");
 	// str = separat_with_one_space("echo bonjour > > out");
 	// str = separat_with_one_space("echo 2 >> out1 > out2");
	// str = separat_with_one_space("echo hudifg d | | hugdfihd");
 	// str = separat_with_one_space("echo");
 	// str = separat_with_one_space("echo simple");
 	// str = separat_with_one_space("echo -n simple");
 	// str = separat_with_one_space("echo \'\'");
 	// str = separat_with_one_space("echo \"\"");
 	// str = separat_with_one_space("echo \"\"");
 	// str = separat_with_one_space("echo \"\n \n \n\"");
 	// str = separat_with_one_space("echo \"\n \n \\n\"");
	// str = separat_with_one_space("echo \'hello|world!\'test_test |cat -e| ls     -la>file     ");
	// str = separat_with_one_space("> a ls > b < Makefile");
	str = separat_with_one_space("echo gg\"hello| cat \" |te world rr  \"dd\" |rl");    
	all(str);
	t_cmd *ptr = (*v_cmd());
	while(ptr)
	{
		printf("%s\n", ptr->content);
		ptr = ptr->next;
	}
}
