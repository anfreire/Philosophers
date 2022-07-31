/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfreire <anfreire@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 08:56:13 by anfreire          #+#    #+#             */
/*   Updated: 2022/07/29 03:00:55 by anfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	routine_aux(t_philo *philo, t_data *data)
{
	if (philo_eats(philo, data))
		return (0);
	philo_sleeps(philo, data);
	check_if_can_proceed(data);
	if (data->philo_died == 1)
		return (1);
	printf("ms:%lld		Philo %d is thinking\n", \
	get_miliseconds(data), philo->philo_nmbr);
	check_if_can_proceed(data);
	if (data->philo_died == 1)
		return (1);
	return (0);
}

int	can_philo_eat(t_philo *philo, t_data *data)
{
	int	i1;
	int	i2;

	i1 = philo->philo_nmbr - 1;
	i2 = philo->philo_nmbr;
	if (philo->philo_nmbr == philo->data->nmbr_philos)
		i2 = 0;
	if (data->forks[i1] && data->forks[i2])
		return (1);
	else
		return (0);
}

static void	mutex_lock(t_philo *philo, t_data *data, int i1, int i2)
{
	data->forks[i1] = 0;
	data->forks[i2] = 0;
	gettimeofday(&philo->t_full, NULL);
	philo->philos_eated++;
	pthread_mutex_lock(&data->philos[i1].forks);
	printf("ms:%lld		Philo %d has taken a fork\n", \
	get_miliseconds(data), philo->philo_nmbr);
	pthread_mutex_lock(&data->philos[i2].forks);
	printf("ms:%lld		Philo %d has taken a fork\n", \
	get_miliseconds(data), philo->philo_nmbr);
	if (data->philo_died == 0)
		printf("ms:%lld		Philo %d is eating\n", \
	get_miliseconds(data), philo->philo_nmbr);
}

int	philo_eats(t_philo *philo, t_data *data)
{
	int	i1;
	int	i2;

	i1 = philo->philo_nmbr - 1;
	i2 = philo->philo_nmbr;
	if (philo->philo_nmbr == philo->data->nmbr_philos)
	{
		i1 = 0;
		i2 = philo->philo_nmbr - 1;
	}
	check_if_can_proceed(data);
	if (can_philo_eat(philo, data))
		mutex_lock(philo, data, i1, i2);
	else
		return (1);
	usleep(data->t_eat * 1000);
	return (0);
}

void	philo_sleeps(t_philo *philo, t_data *data)
{
	int	i1;
	int	i2;

	i1 = philo->philo_nmbr - 1;
	i2 = philo->philo_nmbr;
	if (philo->philo_nmbr == philo->data->nmbr_philos)
	{
		i1 = 0;
		i2 = philo->philo_nmbr - 1;
	}
	data->forks[i1] = 1;
	data->forks[i2] = 1;
	pthread_mutex_unlock(&data->philos[i1].forks);
	pthread_mutex_unlock(&data->philos[i2].forks);
	if (data->philo_died == 0)
		printf("ms:%lld		Philo %d is sleeping\n", \
	get_miliseconds(data), philo->philo_nmbr);
	if (data->philo_died == 0)
		usleep(data->t_sleep * 1000);
}
