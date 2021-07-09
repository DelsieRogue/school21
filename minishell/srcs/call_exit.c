/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 17:05:01 by drogue            #+#    #+#             */
/*   Updated: 2021/05/23 17:08:07 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	my_num_exit(char *s)
{
	unsigned long long	ex;
	int					i;
	int					znak;

	ex = 0;
	znak = 1;
	i = 0;
	if (s[i] == '-' && (znak = -1))
		i++;
	if (s[i] == '+')
		i++;
	if (s[i] < '0' || s[i] > '9')
		return (-1);
	while (s[i] >= '0' && s[i] <= '9')
	{
		ex = 10 * ex + s[i] - '0';
		i++;
		if (ex > 9223372036854775807)
		{
			if (znak == 1 || ex - 9223372036854775807 > 1)
				return (-1);
		}
	}
	return (znak * ex % 256);
}

int	my_exit(char **mas, int *ex, t_his *his)
{
	set_history(his);
	if (!*mas)
		exit(*ex);
	*ex = my_num_exit(*mas);
	if (*ex == -1)
	{
		printf("bash: exit: %s: numeric argument required\n", *mas);
		*ex = 255;
		exit(*ex);
	}
	if (ft_strlen_mas(mas) > 1)
	{
		printf("bash: exit: too many arguments\n");
		*ex = 1;
		return (0);
	}
	exit(*ex);
}
