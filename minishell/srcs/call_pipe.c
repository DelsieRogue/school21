/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawnee <bshawnee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:58:53 by drogue            #+#    #+#             */
/*   Updated: 2021/05/27 13:51:27 by bshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int		child_process(t_data *arg, int *ex, t_his *his, int op)
{
	if (!op)
		dup2(arg->fd[1], 1);
	close(arg->fd[1]);
	apply_red(arg);
	call_functions(arg, ex, his);
	return (0);
}

int		parent_process(t_data *arg)
{
	dup2(arg->fd[0], 0);
	close(arg->fd[0]);
	return (0);
}

int		pipe_proc(t_data *arg, int *ex, t_his *his, int op)
{
	pid_t	i;
	int		fd_0;

	arg->i_pid++;
	fd_0 = dup(arg->fd[0]);
	pipe(arg->fd);
	if ((i = fork()) == -1)
		return (-1);
	if (i == 0)
	{
		dup2(fd_0, 0);
		close(arg->fd[0]);
		close(fd_0);
		child_process(arg, ex, his, op);
		exit(*ex);
	}
	back_redirect(arg);
	arg->pid[arg->i_pid] = i;
	if (op)
		close(arg->fd[0]);
	close(arg->fd[1]);
	free_two_mas(&arg->mas, ft_strlen_mas(arg->mas));
	return (1);
}

void	all_wait(int *ex, int pipe, t_pars *pars, t_data *arg)
{
	int i;
	int status;

	i = 0;
	if (!pipe)
		return ;
	pipe_proc(arg, ex, pars->his, 1);
	waitpid(arg->pid[arg->i_pid], &status, 0);
	*ex = (WEXITSTATUS(status));
	while (i < arg->i_pid)
	{
		kill(arg->pid[i], SIGKILL);
		wait(0);
		i++;
	}
}

int		check_pipe(t_pars *pars)
{
	int i;
	int pipe;

	i = 0;
	pipe = 0;
	while (pars->arg[i])
	{
		if (!ft_strcmp(pars->arg[i], "|"))
		{
			pipe++;
		}
		i++;
	}
	return (pipe);
}
