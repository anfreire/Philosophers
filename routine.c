/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfreire <anfreire@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:27:59 by anfreire          #+#    #+#             */
/*   Updated: 2022/07/07 00:59:11 by anfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void*	routine(void *args)
{
	t_philo *philos;
	int		clock;

	clock = 0;
	philos = (t_philo *)args;
	while (philos->is_full == 0)
	{
		if (clock >= philos->data->t_die)
			philos->data->philos_alive = 0;
		if (can_philo_eat(philos, philos->data))
		{	
			philo_eats(philos, philos->data);
			philo_sleeps(philos, philos->data);
			philo_thinks(philos, philos->data);
		}
		usleep(1000);
		clock++;
	}
	return (NULL);
}

void*	clock_philo(void *args)
{
	t_philo *philos;
	int 	clock;
	
	clock = 0;
	philos = (t_philo *)args;
	while (philos->data->philos_alive == 1)
	{
		if (philos->is_full == 1)
			break ;
		if (clock >= philos->data->t_die)
			philo_died(philos, philos->data);
		usleep(1000);
		clock++;
	}
	return (NULL);
}

void	philo_died(t_philo *philo, t_data *data)
{
	printf("ms:%lld		Philo %d has died\n", get_miliseconds(data), philo->philo_nmbr);
	data->philos_alive = 0;
	destroy_philo(data);
}