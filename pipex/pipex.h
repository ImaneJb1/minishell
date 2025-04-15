/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 01:12:27 by imeslaki          #+#    #+#             */
/*   Updated: 2025/03/08 21:22:00 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_data
{
	pid_t	pid1;
	pid_t	pid2;
	int		pip[2];
	int		fdin;
	int		fdout;
	char	*absolute_path;
	char	**full_cmd;
	// get_path
	char	**cmd;
	char	*cmd_path;
	char	*exec;
	char	**full_paths;
}			t_data;

void		put_str(char *s, int fd);
void		init(t_data *data);
void		wait_function(t_data *data);
int			ft_strlen(const char *str);
void		*free_2d_arry(char **ptr);
char		**ft_split(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

void		check_full_paths(char *full_cmd, t_data *data, char **env);
char		*get_the_absolute_path(char *arg, t_data *data, char **env);
void		execute_cmd(char *arg, t_data *data, char **env);
char		*get_path(char *full_cmd, t_data *data, char **env);
char		*path_in_env(char **env);
void		errors(char *str, t_data *data, int fd);
char		*check_the_absolute_path(char *full_cmd, t_data *data);

void		close_and_dup(t_data *data, int flage);
int			creat_fdin(char *arg, t_data *data);
int			creat_fdout(char *arg, t_data *data);

#endif