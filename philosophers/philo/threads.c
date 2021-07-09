/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 18:45:38 by drogue            #+#    #+#             */
/*   Updated: 2021/06/10 13:18:22 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	print_status(unsigned long time, int id, char *status)
{
	pthread_mutex_lock(&g_data.print_status);
	ft_putnbr_fd(time, 1);
	write(1, "\t", 1);
	ft_putnbr_fd(id, 1);
	write(1, "\t", 1);
	ft_putstr_fd(status, 1);
	pthread_mutex_unlock(&g_data.print_status);
}

unsigned long	get_forks(int left, int rigth)
{
	unsigned long	time;

	pthread_mutex_lock(&g_data.philos[rigth].priority);
	if (rigth % 2 == 0)
	{
		pthread_mutex_lock(&g_data.philos[left].fork);
		print_status(current_time(), rigth + 1, "has taken a fork\n");
		pthread_mutex_lock(&g_data.philos[rigth].fork);
		print_status(current_time(), rigth + 1, "has taken a fork\n");
	}
	else
	{
		pthread_mutex_lock(&g_data.philos[rigth].fork);
		print_status(current_time(), rigth + 1, "has taken a fork\n");
		pthread_mutex_lock(&g_data.philos[left].fork);
		print_status(current_time(), rigth + 1, "has taken a fork\n");
	}
	pthread_mutex_unlock(&g_data.philos[(rigth + 1) % (g_data.num)].priority);
	time = current_time();
	return (time);
}

int	check_filos(void)
{
	unsigned long	time;
	unsigned int	i;
	int				c;

	i = 0;
	c = 0;
	while (i < g_data.num)
	{
		time = current_time();
		if (g_data.philos[i].all_eat < g_data.max_eat)
			c = 1;
		if (time > g_data.philos[i].last_eat && time - g_data.philos[i].last_eat
			> (unsigned long)g_data.time_to_die)
		{
			usleep(5000);
			if (g_data.philos[i].status != EAT)
				return (dead_pthread(i, time));
		}
		i++;
	}
	if (g_data.max_eat && c == 0)
		return (end_prog());
	return (1);
}

void	*start_philos(void *arg)
{
	int				id;
	int				left_f;
	unsigned long	time;

	id = *(int *)arg;
	if (id - 1 < 0)
		left_f = g_data.num - 1;
	else
		left_f = id - 1;
	while (1)
	{
		time = get_forks(left_f, id);
		g_data.philos[id].last_eat = time;
		g_data.philos[id].status = EAT;
		print_status(time, id + 1, "is eating\n");
		usleep(g_data.time_to_eat * 1000);
		g_data.philos[id].status = NOEAT;
		pthread_mutex_unlock(&g_data.philos[id].fork);
		pthread_mutex_unlock(&g_data.philos[left_f].fork);
		print_status(current_time(), id + 1, "is sleep\n");
		g_data.philos[id].all_eat++;
		usleep(g_data.time_to_sleep * 1000);
		print_status(current_time(), id + 1, "is thinking\n");
	}
	return (arg);
}
