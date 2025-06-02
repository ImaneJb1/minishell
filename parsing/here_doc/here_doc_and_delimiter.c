/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_and_delimiter.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:23:30 by imeslaki          #+#    #+#             */
/*   Updated: 2025/06/02 15:36:04 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void	get_delimiter(t_cmd **cmd)
{
	int		i;
	char	*str;
	char	*del;

	i = 0;
	del = NULL;
	str = (*cmd)->content;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] == '$')
		{
			del = ft_strjoin(del, "$$");
			i += 2;
		}
		if (str[i] == '\'')
			del = inside_quote(del, str, &i, '\'');
		if (str[i] == '\"')
			del = inside_quote(del, str, &i, '\"');
		else if (str[i] == '$' && ft_strchr("\"\'", str[i + 1]))
			i++;
		else
			del = join_str_char(del, str[i++]);
	}
	del = unquoted_one_cmd(del);
	(*cmd)->content = del;
}

void	write_in_here_doc_file(t_cmd *del, t_data *info, int *fd)
{
	t_data	*data;

	data = init_data();
	*fd = open(info->word, O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (*fd < 0)
		return (perror(info->word));
	if (!(del->type & (SINGLE_Q | DOUBLE_Q)))
		data->flag = 1;
	while (1)
	{
		data->str = readline("  >> ");
		if (!data->str)
		{
			print_error_to_stderr("Minishell: warning: here-document delimited by end-of-file (wanted `", 
				del->content, "')\n", STDERR_FILENO);
			ft_exit(0);
		}
		if (ft_strcmp(del->content, data->str) == 0)
			break ;
		check_expand_and_put_in_file(data, *fd);
	}
	if(data->str)
		ft_free(data->str);
	close(*fd);
}

int	heredoc_exit_with_signal(int flag)
{
	static int	save_flag;

	if (flag == 1)
		save_flag = 1;
	if (flag == 0)
		save_flag = 0;
	return (save_flag);
}

int	inside_child(int flag)
{
	static int	i;

	if (flag == 1)
		i = 1;
	else if (flag == 0)
		i = 0;
	return (i);
}

void	sigint_in_heredoc_child(int num)
{
	(void)num;
	
	ft_exit(130);
	// ft_free_all();
	// signal(SIGINT, SIG_DFL);
	// kill(getpid(), SIGINT);
	
}

void	heredoc_child_process(t_cmd *token, t_data	*data, int	*fd)
{
	signal(SIGINT, sigint_in_heredoc_child);
	get_delimiter(&token);
	write_in_here_doc_file(token, data, fd);
	free_exit(0);
}

void	heredoc_parent_process(t_data	*data)
{
	inside_child(1);
	waitpid(data->pid, &data->status, 0);
	// if (WIFSIGNALED(data->status))
	// {
	// 	update_exit_status((128 + WTERMSIG(data->status)));
	// 	heredoc_exit_with_signal(1);
	// }
	// printf("is true = %d     exit status = %d\n",WIFEXITED(data->status), WEXITSTATUS(data->status));
	if (WIFEXITED(data->status))
	{
		if(WEXITSTATUS(data->status) == 130)
			heredoc_exit_with_signal(1);
		update_exit_status(WEXITSTATUS(data->status));
	}
	inside_child(0);
}

void	open_fd_heredoc(t_cmd *token, int *fd)
{
	t_data		*data;
	char		*fd_file_name;
	static int	here_num;

	data = init_data();
	fd_file_name = NULL;
	if (token->type & DELIMITER)
	{
		data->word = ft_strjoin("/tmp/", ft_itoa(here_num++));
		*fd = open(data->word, O_CREAT | O_RDWR | O_TRUNC, 0666);
		if (*fd < 0)
			return (perror(fd_file_name));
		data->pid = fork();
		if (data->pid == 0)
			heredoc_child_process(token, data, fd);
		heredoc_parent_process(data);
	}
}
