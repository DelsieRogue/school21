/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:58:10 by bshawnee          #+#    #+#             */
/*   Updated: 2021/05/23 17:56:58 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int		my_echo(char **params)
{
	int	n;
	int	b;
	int	i;

	n = 0;
	i = 0;
	b = 0;
	if (!params[i])
		write(1, "\n", 1);
	while (params[i])
	{
		if (!ft_strcmp(params[i], "-n") && !n)
			b = 1;
		else
		{
			n = 1;
			ft_putstr_fd(params[i], 1);
			if (params[i + 1])
				ft_putchar_fd(' ', 1);
			if (!params[i + 1] && !b)
				ft_putchar_fd('\n', 1);
		}
		i++;
	}
	return (0);
}
