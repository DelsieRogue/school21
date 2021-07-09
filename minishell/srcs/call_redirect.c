/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_redirect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:55:48 by drogue            #+#    #+#             */
/*   Updated: 2021/05/23 16:58:28 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	back_redirect(t_data *arg)
{
	if (arg->lr != -2)
	{
		dup2(arg->save_fd_0, 0);
		arg->lr = -2;
	}
	if (arg->rr != -2)
	{
		dup2(arg->save_fd_1, 1);
		arg->rr = -2;
	}
}

void	apply_red(t_data *arg)
{
	if (arg->lr != -2)
	{
		dup2(arg->lr, 0);
		close(arg->lr);
	}
	if (arg->rr != -2)
	{
		dup2(arg->rr, 1);
		close(arg->lr);
	}
}

int		right_redirect(t_data *arg, t_pars *pars, int i, int *ex)
{
	if (!check_name(arg, pars, i, ex))
		return (-1);
	if (arg->rr != -2)
	{
		close(arg->rr);
		arg->rr = -2;
	}
	arg->rr = open(pars->arg[i + 1], O_TRUNC | O_RDWR |
		O_CREAT, S_IWRITE | S_IREAD);
	if (arg->rr == -1)
		exit(2);
	free(pars->arg[i]);
	free(pars->arg[i + 1]);
	return (2);
}

int		two_right_redirect(t_data *arg, t_pars *pars, int i, int *ex)
{
	if (!check_name(arg, pars, i, ex))
		return (-1);
	if (arg->rr != -2)
	{
		close(arg->rr);
		arg->rr = -2;
	}
	arg->rr = open(pars->arg[i + 1], O_APPEND | O_RDWR |
		O_CREAT, S_IWRITE | S_IREAD);
	if (arg->rr == -1)
		exit(2);
	free(pars->arg[i]);
	free(pars->arg[i + 1]);
	return (2);
}

int		left_redirect(t_data *arg, t_pars *pars, int i, int *ex)
{
	if (!check_name(arg, pars, i, ex))
		return (-1);
	if (arg->lr != -2)
	{
		close(arg->lr);
		arg->lr = -2;
	}
	arg->lr = open(pars->arg[i + 1], O_RDWR, S_IWRITE | S_IREAD);
	if (arg->lr == -1)
	{
		*ex = 1;
		ft_putstr_fd("bash : No such file or directory\n", 2);
		free(arg->mas);
		free_in_mas(pars->arg);
		return (-1);
	}
	free(pars->arg[i]);
	free(pars->arg[i + 1]);
	return (2);
}
