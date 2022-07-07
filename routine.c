/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfreire <anfreire@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:27:59 by anfreire          #+#    #+#             */
/*   Updated: 2022/07/07 01:33:08 by anfreire         ###   ########.fr       */
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
		if (philos->data->philo_died == 1 || philos->data->philos_alive == 0)
			return (NULL);
		if (clock >= philos->data->t_die)
			philos->data->philos_alive = 0;
		if (philos->data->philos_alive == 0)
		{
			printf("ms:%lld		Philo %d has died\n", get_miliseconds(philos->data), philos->philo_nmbr);
			philos->data->philo_died = 1;
			return (NULL);
		}
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
			philo_died(philos->data);
		usleep(1000);
		clock++;
	}
	return (NULL);
}

void	philo_died(t_data *data)
{
	data->philos_alive = 0;
	destroy_philo(data);
}
