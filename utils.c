/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbooker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 12:14:28 by rbooker           #+#    #+#             */
/*   Updated: 2021/07/28 12:14:30 by rbooker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	char_to_int(int i, const char *str, int k)
{
	int			j;
	int			l;
	long long	num;

	num = 0;
	l = 0;
	while (str[i] != '\0' && str[i] <= '9' && str[i] >= '0' && l < 12)
	{
		j = str[i] - '0';
		i++;
		l++;
		num = 10 * num + j;
	}
	if (k * num > 2147483647)
		return (-1);
	else if (k * num < -2147483648)
		return (0);
	else
		return (k * num);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		j;
	int		num;

	i = 0;
	j = 1;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			j = -1;
		i++;
	}
	num = char_to_int(i, str, j);
	return (num);
}

void	print_status(t_philo *philo, char *str, char *clr)
{
	long	begin_time;

	begin_time = philo->all->begin_time;
	if (get_time(begin_time) - philo->last_eat < philo->all->time_to_die)
	{
		pthread_mutex_lock(philo->print);
		printf("%s%lu %d %s\n", clr, get_time(begin_time), philo->id + 1, str);
		pthread_mutex_unlock(philo->print);
	}
}

long	get_time(long begin)
{
	struct timeval	time_struct;
	long			time;

	gettimeofday(&time_struct, NULL);
	time = time_struct.tv_sec * 1000 + time_struct.tv_usec / 1000;
	return (time - begin);
}

void	ft_usleep(int interval)
{
	long	begin;
	long	end;

	begin = get_time(0);
	end = get_time(0) + interval;
	while (begin < end)
	{
		usleep(200);
		begin = get_time(0);
	}
}
