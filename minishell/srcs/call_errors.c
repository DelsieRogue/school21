/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 17:08:43 by drogue            #+#    #+#             */
/*   Updated: 2021/05/27 17:14:10 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	error(char *s, int *ex)
{
	if (*ex == 2)
	{
		*ex = 127;
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(s, 2);
		if (!strncmp("./", s, 2) || !find_env_value("PATH"))
			ft_putstr_fd(": No such file or directory\n", 2);
		else
			ft_putstr_fd(": command not found\n", 2);
	}
	if (*ex == 258)
	{
		ft_putstr_fd("bash: syntax error near unexpected token `", 2);
		ft_putstr_fd(s, 2);
		write(2, "'\n", 2);
	}
	if (*ex == 13)
	{
		*ex = 126;
		ft_putstr_fd("bash:", 2);
		ft_putstr_fd(s, 2);
		ft_putstr_fd(": Permission denied\n", 2);
	}
}

int		check_name(t_data *arg, t_pars *pars, int i, int *ex)
{
	if (!ft_strcmp(pars->arg[i + 1], ">>") ||
		!ft_strcmp(pars->arg[i + 1], ">") ||
			!ft_strcmp(pars->arg[i + 1], "<") ||
				!ft_strcmp(pars->arg[i + 1], "|"))
	{
		*ex = 258;
		ft_putstr_fd("bash: syntax error near unexpected token `", 2);
		ft_putstr_fd(pars->arg[i + 1], 2);
		write(2, "'\n", 2);
		free(arg->mas);
		free_in_mas(pars->arg);
		return (0);
	}
	return (1);
}

void	error_pipe(t_data *arg, t_pars *pars, int *ex, int j)
{
	int i;

	i = 0;
	ft_putstr_fd("bash: fork: Resource temporarily unavailable\n", 2);
	*ex = 1;
	free_two_mas(&arg->mas, ft_strlen_mas(arg->mas));
	while (i < arg->i_pid)
	{
		kill(arg->pid[i], SIGKILL);
		wait(0);
		i++;
	}
	j++;
	while (pars->arg[j])
	{
		free(pars->arg[j]);
		j++;
	}
}
