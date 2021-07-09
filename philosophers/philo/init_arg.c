/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:15:10 by drogue            #+#    #+#             */
/*   Updated: 2021/06/10 15:40:32 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int	check_simvols(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	init_philos(void)
{
	unsigned int	i;

	i = 0;
	while (i < g_data.num)
	{
		g_data.philos[i].id = i;
		g_data.philos[i].last_eat = current_time();
		g_data.philos[i].all_eat = 0;
		pthread_mutex_init(&g_data.philos[i].fork, NULL);
		pthread_mutex_init(&g_data.philos[i].priority, NULL);
		i++;
	}
}

int	init_arg(char **argv)
{
	struct timeval	tv;

	if (!check_simvols(argv))
		return (0);
	g_data.num = ft_atoi(argv[1]);
	g_data.time_to_die = ft_atoi(argv[2]);
	g_data.time_to_eat = ft_atoi(argv[3]);
	g_data.time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		g_data.max_eat = ft_atoi(argv[5]);
	else
		g_data.max_eat = 0;
	if (g_data.num <= 1 || g_data.num > 200 || g_data.time_to_die < 60
		|| g_data.time_to_eat < 60 || g_data.time_to_sleep < 60
		|| (argv[5] && g_data.max_eat <= 1))
		return (0);
	g_data.philos = (t_philos *)malloc(sizeof(t_philos) * g_data.num);
	init_philos();
	pthread_mutex_init(&g_data.print_status, NULL);
	gettimeofday(&tv, NULL);
	g_data.start_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (1);
}
