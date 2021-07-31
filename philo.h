/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbooker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 12:15:30 by rbooker           #+#    #+#             */
/*   Updated: 2021/07/28 12:15:33 by rbooker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_maj_struct
{
	int				num_of_philos;
	long			time_to_die;
	int				time_to_sleep;
	int				time_to_eat;
	int				eat_times;
	int				flag_eat_times;
	pthread_t		*thread;
	pthread_mutex_t	*mutex;
	long			begin_time;
	pthread_mutex_t	print;
}				t_maj_struct;

typedef struct s_philo
{
	t_maj_struct	*all;
	int				id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	long			last_eat;
	int				eat_count;
	int				flag_eat_count;
	pthread_mutex_t	*print;
}				t_philo;

pthread_mutex_t prnt;

int		init_mutex(t_maj_struct *all);
t_philo	*init_philo(t_maj_struct *all);
int		launch_philos(t_philo *philo, t_maj_struct *all);
void	*action(void *my_struct);
void	*monitor(void *my_struct);
void	print_status(t_philo *philo, char *str, char *clr);
long	get_time(long begin);
void	ft_usleep(int interval);
int		ft_atoi(const char *str);

#endif
