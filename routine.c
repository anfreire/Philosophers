/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfreire <anfreire@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:27:59 by anfreire          #+#    #+#             */
/*   Updated: 2022/07/26 21:55:37 by anfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	check_if_all_philos_eaten(t_data *data)
{
	int	i;

	i = 0;
	if (data->nmbr_philo_eat == 0)
		return ;
	if (data->philo_died == 1)
		return ;
	while (i < data->nmbr_philos)
	{
		if (data->philos[i].philos_eated != data->nmbr_philo_eat)
			return ;
		i++;
	}
	data->philo_died = 1;
}

void	check_if_philo_is_dead(t_data *data, t_philo *philo)
{
	if (data->philo_died == 1)
		return ;
	if (get_miliseconds_hunger(philo) >= (long long)data->t_die)
	{
		if (data->philo_died == 1)
			return ;
		data->philo_died = 1;
		printf("ms:%lld		Philo %d has died\n", \
		get_miliseconds(data), philo->philo_nmbr);
		return ;
	}
}

void	philo_routine(t_data *data, t_philo *philo)
{
	if (check_if_can_proceed(philo, data) == 0)
		philo_eats(philo, data);
	else
		return ;
	philo_sleeps(philo, data);
	if (check_if_can_proceed(philo, data) == 0)
		philo_thinks(philo, data);
	else
		return ;
}

long long	get_miliseconds_hunger(t_philo *philo)
{
	long long		sec;
	long long		usec;
	struct timeval	t_now;

	gettimeofday(&t_now, NULL);
	sec = t_now.tv_sec - philo->t_full.tv_sec;
	usec = t_now.tv_usec - philo->t_full.tv_usec;
	return ((usec / 1000) + (sec * 1000));
}

void	*routine(void *args)
{
	t_philo	*philos;
	t_data	*data;

	philos = (t_philo *)args;
	data = (t_data *)philos->data;
	data->start++;
	philos->t_full = data->t_start;
	while (check_if_can_proceed(philos, data) == 0)
	{
		if (can_philo_eat(philos, data))
			philo_routine(data, philos);
		if (check_if_can_proceed(philos, data))
			return (NULL);
	}
	return (NULL);
}
