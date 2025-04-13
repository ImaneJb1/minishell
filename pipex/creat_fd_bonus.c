/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_fd_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 08:14:13 by imeslaki          #+#    #+#             */
/*   Updated: 2025/03/11 19:39:39 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	creat_fdin_bonus(char *arg, t_data *data)
{
	data->fdin = open(arg, O_RDONLY, 0666);
	if (data->fdin < 0)
	{
		close(data->pipes[0][1]);
		data->pipes[0][1] = -1;
		free_2d_arry_of_integers_bonus(data->pipes, data->number_of_loops);
		free(data->pid);
		errors_bonus(arg, data, -1);
	}
	return (data->fdin);
}

int	creat_fdout_bonus(char *arg, t_data *data, int nbr_pipe)
{
	data->fdout = open(arg, O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (data->fdout < 0)
	{
		close(data->pipes[nbr_pipe - 1][0]);
		data->pipes[nbr_pipe - 1][0] = -1;
		free_2d_arry_of_integers_bonus(data->pipes, data->number_of_loops);
		free(data->pid);
		errors_bonus(arg, data, -1);
	}
	return (data->fdout);
}

void	creat_fd_for_onecmd_bonus(char *in, char *out, t_data *data)
{
	data->fdin = open(in, O_CREAT | O_RDWR, 0666);
	if (data->fdin < 0)
		exit(1);
	data->fdout = open(out, O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (data->fdout < 0)
		exit(1);
}

// char    **all_conditions(char **av,t_data  *data)
// {
//     int i;

//     i = 2;
//     data->delemiter = av[2];
//     while(av[i + 1])
//     {
//         av[i] = av[i + 1];
//         i++;
//     }
//     data->fdin = here_doc(av[1], &data);
//     av[i] = NULL;
//     return (av);
// }

// int main(int ac, char **av, char **env)
// {
//     t_data  data;

//     init(&data);
//     if(ft_strcmp(av[1], "here_doc") == 1)
//         av =  all_conditions(av,&data);
//     int i = 0;
//     while(av[i])
//     {
//         printf("%s ",av[i]);
//         i++;
//     }
//     exit(2);