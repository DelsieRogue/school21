/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 18:47:27 by drogue            #+#    #+#             */
/*   Updated: 2021/06/10 15:37:39 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int	end_prog(void)
{
	pthread_mutex_lock(&g_data.print_status);
	if (g_data.philos)
		free(g_data.philos);
	return (0);
}

int	dead_pthread(int i, unsigned long time)
{
	pthread_mutex_lock(&g_data.print_status);
	ft_putnbr_fd(time, 1);
	write(1, "\t", 1);
	ft_putnbr_fd(i + 1, 1);
	write(1, "\t", 1);
	ft_putstr_fd("died\n", 1);
	pthread_mutex_unlock(&g_data.print_status);
	return (end_prog());
}
