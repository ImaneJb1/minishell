
#include "execution/built_ins/built_in.h"
#include "minishell.h"
// #include "./execution/built_ins/built_in.h"
#include "./parsing/parsing.h"

int		exit_status;

void	print_parsing(void)
{
	t_cmd	*ptr;

	ptr = *v_cmd();
	printf("----------------------------------------------\n");
	printf("                    PARSING                   \n");
	printf("----------------------------------------------\n");
	while (ptr)
	{
		printf("[%s] = ", ptr->content);
		if (ptr->type & WORD)
			printf("WORD ");
        if (ptr->type & FIELD)
			printf("FIELD ");
		if (ptr->type & FILE_NAME)
			printf("FILE_NAME ");
		if (ptr->type & CMD)
			printf("CMD ");
		if (ptr->type & CMD_ARG)
			printf("CMD_ARG ");
		if (ptr->type & DOUBLE_Q)
			printf("DOUBLE_Q ");
		if (ptr->type & SINGLE_Q)
			printf("SINGLE_Q ");
		if (ptr->type & PIPE)
			printf("PIPE ");
		if (ptr->type & HERE_DOC)
			printf("HERE_DOC ");
		if (ptr->type & REDIR_IN)
			printf("REDIR_IN ");
		if (ptr->type & REDIR_OUT)
			printf("REDIR_OUT ");
		if (ptr->type & APPEND)
			printf("APPEND ");
		if (ptr->type & PATH)
			printf("PATH ");
		if (ptr->type & VARIABLE)
			printf("VARIABLE");
		if (ptr->type & DELIMITER)
			printf("DELIMITER");
		printf("  (%d) ", ptr->index);
		ptr = ptr->next;
		printf("\n");
	}
	printf("----------------------------------------------\n");
	printf("----------------------------------------------\n");
}

void	handle_sig_int(int flag)
{
	flag = inside_child(2);
	if (flag == 0)
	{
		rl_replace_line("", 0);
		write(1, "\n", 1);
		rl_on_new_line();
		rl_redisplay();
		update_exit_status(130);
	}
	else if (flag == 1)
		write(1, "\n", 1);
}

int	is_error(int flag)
{
	static int	i;

	if(flag == 0)
		i = 0;
	else if(flag == 1)
		i = 1;
	return i;
}

void   print_error_to_stderr(char *s1, char *s2, char *s3, int fd)
{
    ft_putstr_fd(s1, fd);
    ft_putstr_fd(s2, fd);
    ft_putstr_fd(s3, fd);
}

int	main(int argc, char const *argv[], char **env)
{
	char	*str;

	(void)argv;
	(void)argc;
	signal(SIGINT, handle_sig_int);
	signal(SIGQUIT, SIG_IGN);
	create_environment(env);
	while (1)
	{
		str = readline("Minishell $>: ");
		if (!str)
			ft_exit(exit_status);
		if (!*str)
			continue ;
		add_history(str);
		if (!parsing(str))
		{
			lstclear_exec();
			continue ;
		}
		
		main_execution();
		lstclear_exec();
	}
}
