/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 23:25:35 by imeslaki          #+#    #+#             */
/*   Updated: 2025/03/09 01:51:26 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "./get_next_line/get_next_line_bonus.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_data_b
{
	int		number_of_loops;
	int		number_of_pipes;
	int		last_cmd;
	int		cur_loop;
	int		**pipes;
	int		*pid;
	int		fdin;
	int		fdout;
	char	*absolute_path;
	char	**full_cmd;
	char	*delemiter;

	char	**cmd;
	char	*cmd_path;
	char	*exec;
	char	**full_paths;

}			t_data;

void		init(t_data *data);
void		write_in_file(char *s, int fd);
char		*get_next_line(int fd, char *delemiter);
int			here_doc(char *arg, t_data *data);
void		free_all(t_data *data);
void		wait_function_bonus(int *pid, int max);
int			**allocat_for_pipes(int number_of_pip);
int			*allocat_for_pid(int number_of_pid, t_data *data);
void		last_child(char **av, t_data *data, char **env);
void		execut_childs(char **av, t_data *data, char **env);
void		child_proccess(char **av, t_data *data, char **env);
void		dup_close_first_cmd_bonus(t_data *data);
void		dup_close_middle_cmds_bonus(t_data *data);
void		dup_close_last_cmd_bonus(t_data *data);
void		dup_close_one_cmd_bonus(t_data *data);
void		close_pipes(t_data *data);

void		execute_cmd_bonus(char *arg, t_data *data, char **env);
char		**get_full_cmd_bonus(char *arg, t_data *data);
void		creat_fd_for_onecmd_bonus(char *in, char *out, t_data *data);
int			creat_fdout_bonus(char *arg, t_data *data, int ac);
int			creat_fdin_bonus(char *arg, t_data *data);
char		*get_absolute_path_bonus(char *arg, t_data *data, char **env);
char		*get_path_bonus(char *full_cmd, t_data *data, char **env);
void		free_2d_arry_of_integers_bonus(int **ptr, int size);
int			ft_strlen_bonus(const char *str);
void		free_2d_arry_bonus(char **ptr);
char		**ft_split_bonus(char const *s, char c);
char		*ft_substr_bonus(char const *s, unsigned int start, size_t len);
char		*ft_strdup_bonus(const char *s1);
char		*ft_strjoin_bonus(char const *s1, char const *s2);
int			ft_strncmp_bonus(const char *s1, const char *s2, size_t n);
int			ft_strcmp(char *str1, char *str2);

void		check_full_paths(char *full_cmd, t_data *data, char **env);
char		*path_in_env_bonus(char **env);
void		errors_bonus(char *str, t_data *data, int fd);
char		*check_the_absolute_path_bonus(char *full_cmd, t_data *data);

#endif
