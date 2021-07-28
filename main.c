/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbooker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 12:14:20 by rbooker           #+#    #+#             */
/*   Updated: 2021/07/28 12:14:22 by rbooker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_data(int argc, char *argv[], t_maj_struct *all)
{
	all->flag_eat_times = 0;
	all->flag_death = 0;
	all->num_of_philos = ft_atoi(argv[1]);
	all->time_to_die = ft_atoi(argv[2]);
	all->time_to_eat = ft_atoi(argv[3]);
	all->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		all->flag_eat_times = 1;
		all->eat_times = ft_atoi(argv[5]);
	}
	if (all->num_of_philos < 1 || all->time_to_die < 1 || all->time_to_eat < 1 \
	|| all->time_to_sleep < 1 || (all->flag_eat_times && all->eat_times < 1))
	{
		printf("Not valid arguments\n");
		return (0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_maj_struct	all;
	t_philo			*philo;

	if (argc == 6 || argc == 5)
	{
		if (!check_data(argc, argv, &all))
			return (0);
		if (!init_mutex(&all))
			return (0);
		philo = init_philo(&all);
		if (!philo)
			return (0);
		if (!launch_philos(philo, &all))
			return (0);
		free(all.mutex);
		free(all.thread);
		free(philo);
	}
	else
	{
		printf("Not valid arguments\n");
		return (0);
	}
}
