/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawnee <bshawnee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:08:43 by drogue            #+#    #+#             */
/*   Updated: 2021/05/27 13:46:47 by bshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	init_arg(t_data *arg)
{
	arg->mas = NULL;
	arg->save_fd_0 = dup(0);
	arg->save_fd_1 = dup(1);
	arg->rr = -2;
	arg->lr = -2;
	ft_memset(arg->pid, 0, sizeof(pid_t) * 1024);
	arg->i_pid = -1;
	arg->fd[0] = 0;
	arg->fd[1] = 1;
	arg->pipe = 0;
}

int		call_functions(t_data *arg, int *ex, t_his *his)
{
	apply_red(arg);
	if (!ft_strcmp(arg->mas[0], "exit") && write(1, "exit\n", 5))
		return (my_exit(&arg->mas[1], ex, his));
	*ex = 0;
	if (!ft_strcmp(arg->mas[0], "echo"))
		my_echo(&arg->mas[1]);
	else if (!ft_strcmp(arg->mas[0], "env"))
		print_env();
	else if (!ft_strcmp(arg->mas[0], "export"))
		export(&arg->mas[1], ex);
	else if (!ft_strcmp(arg->mas[0], "cd"))
		*ex = cd(arg->mas[1]);
	else if (!ft_strcmp(arg->mas[0], "unset"))
		unset(&arg->mas[1]);
	else if (!ft_strcmp(arg->mas[0], "pwd"))
		printf("%s\n", find_env_value("PWD"));
	else
		proc_execve(arg, ex);
	if (*ex != 0)
		error(arg->mas[0], ex);
	back_redirect(arg);
	free_two_mas(&arg->mas, ft_strlen_mas(arg->mas));
	return (0);
}

int		check_simvols(t_data *arg, t_pars *pars, int i, int *ex)
{
	int ret;

	if (!ft_strcmp(pars->arg[i], ">"))
		return (right_redirect(arg, pars, i, ex));
	else if (!ft_strcmp(pars->arg[i], ">>"))
		return (two_right_redirect(arg, pars, i, ex));
	else if (!ft_strcmp(pars->arg[i], "<"))
		return (left_redirect(arg, pars, i, ex));
	else if (!ft_strcmp(pars->arg[i], "|"))
	{
		if (!check_name(arg, pars, i, ex))
			return (-1);
		free(pars->arg[i]);
		if ((ret = pipe_proc(arg, ex, pars->his, 0)) == -1)
			error_pipe(arg, pars, ex, i);
		return (ret);
	}
	return (0);
}

void	loop_processing(t_data *arg, t_pars *pars, int *ex)
{
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	while (pars->arg[i])
	{
		if (pars->arg[i + 1] && (ret = check_simvols(arg, pars, i, ex)))
		{
			if (ret == -1)
				return ;
			i += ret;
		}
		else
		{
			add_new_str(pars->arg[i], &arg->mas);
			i++;
		}
	}
	if (!arg->pipe)
		call_functions(arg, ex, pars->his);
	else
		all_wait(ex, arg->pipe, pars, arg);
}

int		array_processing(t_pars *pars, int *ex)
{
	t_data arg;

	init_arg(&arg);
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	arg.pipe = check_pipe(pars);
	loop_processing(&arg, pars, ex);
	close(arg.save_fd_0);
	close(arg.save_fd_1);
	return (0);
}
