/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_lounch.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbooker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 12:14:10 by rbooker           #+#    #+#             */
/*   Updated: 2021/07/28 12:14:12 by rbooker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_maj_struct *all)
{
	int	i;

	all->thread = malloc((all->num_of_philos + 1) * sizeof(pthread_t));
	all->mutex = malloc((all->num_of_philos + 1) * sizeof(pthread_mutex_t));
	if (!all->mutex || !all->thread)
	{
		printf("Memory is not located\n");
		return (0);
	}
	i = 0;
	while (i < all->num_of_philos)
	{
		if (pthread_mutex_init(&all->mutex[i], NULL))
		{
			printf("Mutex is not init\n");
			return (0);
		}
		i++;
	}
	return (1);
}

t_philo	*init_philo(t_maj_struct *all)
{
	t_philo	*philo;
	int		i;

	philo = malloc(all->num_of_philos * sizeof(t_philo));
	if (!philo)
	{
		printf("Memory is not located\n");
		return (NULL);
	}
	i = 0;
	while (i < all->num_of_philos)
	{
		philo[i].all = all;
		philo[i].id = i;
		if (i == 0)
			philo[i].left_fork = &all->mutex[all->num_of_philos - 1];
		else
			philo[i].left_fork = &all->mutex[i - 1];
		philo[i].right_fork = &all->mutex[i];
		i++;
	}
	return (philo);
}

int	launch_philos(t_philo *philo, t_maj_struct *all)
{
	int	i;
	int	nop;

	i = 0;
	all->begin_time = get_time(0);
	while (i < all->num_of_philos)
	{
		pthread_create(&all->thread[i], NULL, action, (void *) &philo[i]);
		i++;
	}
	nop = all->num_of_philos;
	pthread_create(&all->thread[nop], NULL, monitor, (void *) philo);
	pthread_join(all->thread[all->num_of_philos], NULL);
	i = 0;
	while (i < all->num_of_philos)
		pthread_detach(all->thread[i++]);
	return (1);
}
