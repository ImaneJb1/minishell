
#include "parsing.h"

int	is_arg(char *str, int *i)
{
	if(str[*i] && !ft_strchr(" \"\'|<>$", str[*i]))
	{
		while (str[*i] && !ft_strchr(" \"\'|<>$", str[*i]))
		{
    		write(1,&str[*i], 1);
			(*i)++;
		}
		write(1,"\n",1);
		return 1;
	}
	return 0;
}

int	is_pipe(char *str, int *i)
{
	if (str[*i] && str[*i] == '|')
	{
        write(1,&str[*i], 1);
		(*i)++;
		write(1,"\n",1);
		return 1;
	}
	return 0;
}

int	is_singl_quoat(char *str, int *i)
{
	int flag;

	flag = 0;
	if (str[*i] && str[*i] == '\'')
	{
        write(1,&str[*i], 1);
		(*i)++;
		while (str[*i])
		{
			if(( str[*i] != '\'' && flag == 0) || (!ft_strchr(" \"\'|<>$", str[*i]) && flag == 1))
            {
				write(1,&str[*i], 1);
				(*i)++;
			}
			else if (str[*i] == '\'' && !ft_strchr(" |<>$", str[*i + 1]))
			{
				flag = 1;
				write(1,&str[*i], 1);
				(*i)++;
			}
			else
            {
				if(str[*i] == '\'' && ft_strchr(" |<>$", str[*i + 1]))
				{
					write(1,&str[*i], 1);
					(*i)++;
				}
			    break;
			}
		}
		write(1,"\n",1);
        return 1;
	}
    return 0;
}

int	is_double_quoat(char *str, int *i)
{
	int flag;

	flag = 0;
	if (str[*i] == '\"')
	{
        write(1,&str[*i], 1);
		(*i)++;
		while (str[*i])
		{
			if(( str[*i] != '\"' && flag == 0) || (!ft_strchr(" \"\'|<>$", str[*i]) && flag == 1))
            {
				write(1,&str[*i], 1);
				(*i)++;
			}
			else if (str[*i] == '\"' && !ft_strchr(" |<>$", str[*i + 1]))
			{
				flag = 1;
				write(1,&str[*i], 1);
				(*i)++;
			}
			else
            {
				if(str[*i] == '\"' && ft_strchr(" |<>$", str[*i + 1]))
				{
					write(1,&str[*i], 1);
					(*i)++;
				}	
			    break;
			}
		}
		write(1,"\n",1);
        return 1;
	}
    return 0;
}

int	is_reder_in(char *str, int *i)
{
	if (str[*i] && str[*i] == '<')
	{
        write(1,&str[*i], 1);
		(*i)++;
		write(1,"\n",1);
		return 1;
	}
	return 0;
}

int	is_reder_out(char *str, int *i)
{
	if (str[*i] && str[*i] == '>')
	{
        write(1,&str[*i], 1);
		(*i)++;
		write(1,"\n",1);
		return 1;
	}
	return 0;
}
//	echo hell >> 
int	is_reder_out_append(char *str, int *i)
{
	if (str[*i] && str[*i + 1] && str[*i] == '>' && str[*i + 1] == '>')
	{
        write(1,&str[*i], 1);
		write(1,&str[*i + 1], 1);
		(*i) += 2;
		write(1,"\n",1);
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
        write(1,&str[*i], 1);
		write(1,&str[*i + 1], 1);
		(*i) += 2;
		write(1,"\n",1);
		return 1;
	}
	return 0;
}

int	is_var(char *str, int *i)
{
	if (str[*i] && str[*i] == '$')
	{
        write(1,&str[*i], 1);
		(*i)++;
		write(1,"\n",1);
        return 1;
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
			// write(1,"\n",1);
			i++;
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
	}
}

int	main(void)
{
    char *str;

	// str = "echo bonjour ; |";
 	// str = "echo bonjour | |";
 	// str = "|";
 	// str = "echo bonjour |;";
 	// str = "echo bonjour ; ls";
 	// str = "echo bonjour > test\ 1";
 	// str = "cd $HOME/Documents";
 	// str = "echo \"\s\" & echo \"\s\"";
 	// str = "echo >";
 	// str = "echo -n -n -nnnn -nnnnm";
 	// str = "cat /dev/random | head -n 1 | cat -e";
 	// str = "unset var1 # with undefined var1";
 	// str = "export "" et unset """;
 	// str = "echo test > file test1";
 	// str = "$";
 	// str = "not_cmd bonjour > salut";
 	// str = "env puis export puis env # vars aren't sorted";
 	// str = "cat Makefile | grep pr | head -n 5 | cd test (mybin) # check status code";
 	// str = "cat Makefile | grep pr | head -n 5 | cat test (bin) # check status code";
 	// str = "cat Makefile | grep pr | head -n 5 | hello (NA) # check status code";
 	// str = "echo bonjour >>> test";
 	// str = "echo bonjour > > out";
 	// str = "echo 2 >> out1 > out2";
	// str = "echo hudifg d | | hugdfihd";
 	// str = "echo";
 	// str = "echo simple";
 	// str = "echo -n simple";
 	// str = "echo \'\'";
 	// str = "echo \"\"";
 	// str = "echo \"\"";
 	// str = "echo \"\n \n \n\"";
 	// str = "echo \"\n \n \\n\"";
	// str = "echo \'hello|world!\'test_test |cat -e| ls     -la>file     ";
	// str = "> a ls > b < Makefile";
	str = separat_with_one_space("echo        hello ggggg \'	 hello gg \' <<<< q>>>d>>q  v < c ls  z>>z< a << a  | cat");
    
	all(str);

}