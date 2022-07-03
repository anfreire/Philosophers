/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfreire <anfreire@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 08:56:13 by anfreire          #+#    #+#             */
/*   Updated: 2022/07/03 17:05:50 by anfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	forks_lock(t_data *data, int i1, int i2)
{
	pthread_mutex_lock(&data->philo.forks[i1]);
	pthread_mutex_lock(&data->philo.forks[i2]);
}

static void	forks_unlock(t_data *data, int i1, int i2)
{
	pthread_mutex_unlock(&data->philo.forks[i1]);
	pthread_mutex_unlock(&data->philo.forks[i2]);
	pthread_cond_wait(&data->philo.cond[i1], &data->philo.forks[i1]);
}

void philo_eats(t_data *data, int philo_nmbr)
{
	int i1;
	int i2;

	i1 = philo_nmbr - 1;
	i2 = philo_nmbr;
	if (philo_nmbr == data->nmbr_philos)
		i2 = 0;
	forks_lock(data, i1, i2);
	printf("ms:%lld		Philo %d has taken a fork\n", get_miliseconds(data), philo_nmbr);
	printf("ms:%lld		Philo %d has taken a fork\n", get_miliseconds(data), philo_nmbr);
	printf("ms:%lld		Philo %d is eating\n", get_miliseconds(data), philo_nmbr);
	usleep(data->t_eat * 1000);
	forks_unlock(data, i1, i2);
	pthread_cond_broadcast(&data->philo.cond[philo_nmbr - 1]);
	// philo_sleeps_n_thinks(data, philo_nmbr);
}

void philo_sleeps_n_thinks(t_data *data, int philo_nmbr)
{
	printf("ms:%lld	Philo %d is sleeping\n", get_miliseconds(data), philo_nmbr);
	usleep(data->t_sleep * 1000);
}
