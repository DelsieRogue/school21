/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:12:25 by drogue            #+#    #+#             */
/*   Updated: 2021/06/10 13:03:25 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		write(fd, s, ft_strlen(s));
	}
}

void	ft_putnbr_fd(unsigned long k, int fd)
{
	char	c;

	c = k + '0';
	if (k > 9)
	{
		ft_putnbr_fd(k / 10, fd);
		ft_putnbr_fd(k % 10, fd);
	}
	else
	{
		write(1, &c, 1);
	}
}

unsigned long	current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000 + tv.tv_usec / 1000) - g_data.start_time);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				znak;
	unsigned long	rez;

	i = 0;
	znak = 1;
	rez = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == ' '
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		return (-1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		rez = 10 * rez + str[i] - '0';
		if (rez > 100000)
			return (-1);
		i++;
	}
	return ((int)(rez)*znak);
}
