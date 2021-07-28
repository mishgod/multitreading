/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbooker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 12:13:57 by rbooker           #+#    #+#             */
/*   Updated: 2021/07/28 12:14:03 by rbooker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *my_struct)
{
	int			i;
	t_philo		*philo;
	int			filled;

	philo = (t_philo *) my_struct;
	ft_usleep(200);
	while (1)
	{
		filled = 0;
		i = 0;
		while (i < philo->all->num_of_philos)
		{
			if (philo[i].flag_eat_count)
				filled++;
			if (get_time(0) - philo[i].last_eat >= philo->all->time_to_die)
			{
				philo->all->flag_death = 1;
				print_status(&philo[i], "died", "\x1b[31m");
				return (NULL);
			}
			i++;
		}
		if (filled == philo->all->num_of_philos && philo->all->flag_eat_times)
			return (NULL);
	}
}

t_philo	*set_vars(void *my_struct)
{
	t_philo	*philo;

	philo = (t_philo *) my_struct;
	philo->eat_count = 0;
	philo->last_eat = philo->all->begin_time;
	philo->flag_eat_count = 0;
	if (philo->id % 2 == 0)
		ft_usleep(philo->all->time_to_eat / 2);
	return (philo);
}

void	ft_eating(t_philo *philo)
{
	print_status(philo, "is eating", "\x1b[33m");
	philo->last_eat = get_time(0);
	philo->eat_count++;
	if (philo->eat_count >= philo->all->eat_times)
		philo->flag_eat_count = 1;
	ft_usleep(philo->all->time_to_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	*action(void *my_struct)
{
	t_philo	*philo;

	philo = set_vars(my_struct);
	while (1)
	{
		pthread_mutex_lock(philo->right_fork);
		if (philo->all->flag_death)
			break ;
		print_status(philo, "has taken right fork", "\x1b[34m");
		pthread_mutex_lock(philo->left_fork);
		if (philo->all->flag_death)
			break ;
		print_status(philo, "has taken left fork", "\x1b[34m");
		if (philo->all->flag_death)
			break ;
		ft_eating(philo);
		if (philo->all->flag_death)
			break ;
		print_status(philo, "is sleeping", "\x1b[35m");
		ft_usleep(philo->all->time_to_sleep);
		if (philo->all->flag_death)
			break ;
		print_status(philo, "is thinking", "\x1b[0m");
	}
	return (NULL);
}
