/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:51:50 by drogue            #+#    #+#             */
/*   Updated: 2021/06/10 15:26:13 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	start_action(void)
{
	unsigned int	i;

	i = 0;
	while (i < g_data.num)
	{
		g_data.philos[i].last_eat = current_time();
		pthread_create(&g_data.philos[i].thread, NULL,
			start_philos, &g_data.philos[i].id);
		pthread_detach(g_data.philos[i].thread);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	a;

	a = 0;
	if (argc < 5 || argc > 6 || !init_arg(argv))
		return (0 * write(1, "error\n", 6));
	start_action();
	while (1)
	{
		if (!check_filos())
			break ;
	}
	return (0);
}
