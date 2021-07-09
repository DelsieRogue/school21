/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <drogue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:12:49 by drogue            #+#    #+#             */
/*   Updated: 2021/06/10 13:17:48 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

# define NOEAT  0
# define EAT	1

typedef struct s_philos
{
	int				id;
	unsigned long	last_eat;
	long			all_eat;
	int				status;
	pthread_t		thread;
	pthread_mutex_t	fork;
	pthread_mutex_t	priority;
}					t_philos;

typedef struct s_data
{
	long			num;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			max_eat;
	t_philos		*philos;
	pthread_mutex_t	print_status;
	unsigned long	start_time;
}					t_data;

t_data	g_data;

void			start_action(void);

size_t			ft_strlen(const char *s);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(unsigned long k, int fd);
int				ft_atoi(const char *str);
unsigned long	current_time(void);

int				check_simvols(char **argv);
void			init_philos(void);
int				init_arg(char **argv);

void			print_status(unsigned long time, int id, char *status);
unsigned long	get_forks(int left, int rigth);
int				check_filos(void);
void			*start_philos(void *arg);

int				end_prog(void);
int				dead_pthread(int i, unsigned long time);
#endif
