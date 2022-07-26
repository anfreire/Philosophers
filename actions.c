/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfreire <anfreire@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 08:56:13 by anfreire          #+#    #+#             */
/*   Updated: 2022/07/26 21:55:42 by anfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	can_philo_eat(t_philo *philo, t_data *data)
{
	int	i1;
	int	i2;

	i1 = philo->philo_nmbr - 1;
	i2 = philo->philo_nmbr;
	if (philo->philo_nmbr == philo->data->nmbr_philos)
		i2 = 0;
	if (data->forks[i1] == 1 && data->forks[i2] == 1)
		return (1);
	else
		return (0);
}

static void	mutex_lock(t_data *data, int i1, int i2)
{
	pthread_mutex_lock(&data->philos[i1].forks);
	pthread_mutex_lock(&data->philos[i2].forks);
	data->forks[i1] = 0;
	data->forks[i2] = 0;
}

void	philo_eats(t_philo *philo, t_data *data)
{
	int	i1;
	int	i2;

	i1 = philo->philo_nmbr - 1;
	i2 = philo->philo_nmbr;
	if (philo->philo_nmbr == philo->data->nmbr_philos)
		i2 = 0;
	if (check_if_can_proceed(philo, data))
		return ;
	gettimeofday(&philo->t_full, NULL);
	mutex_lock(data, i1, i2);
	printf("ms:%lld		Philo %d has taken a fork\n", \
	get_miliseconds(data), philo->philo_nmbr);
	printf("ms:%lld		Philo %d has taken a fork\n", \
	get_miliseconds(data), philo->philo_nmbr);
	printf("ms:%lld		Philo %d is eating\n", \
	get_miliseconds(data), philo->philo_nmbr);
	philo->philos_eated++;
	usleep(data->t_eat * 1000);
	if (check_if_can_proceed(philo, data))
		return ;
}

void	philo_sleeps(t_philo *philo, t_data *data)
{
	int	i1;
	int	i2;

	i1 = philo->philo_nmbr - 1;
	i2 = philo->philo_nmbr;
	if (philo->philo_nmbr == philo->data->nmbr_philos)
		i2 = 0;
	if (check_if_can_proceed(philo, data))
		return ;
	pthread_mutex_unlock(&data->philos[i1].forks);
	pthread_mutex_unlock(&data->philos[i2].forks);
	data->forks[i1] = 1;
	data->forks[i2] = 1;
	printf("ms:%lld		Philo %d is sleeping\n", \
	get_miliseconds(data), philo->philo_nmbr);
	usleep(data->t_sleep * 1000);
	if (check_if_can_proceed(philo, data))
		return ;
}

void	philo_thinks(t_philo *philo, t_data *data)
{
	printf("ms:%lld		Philo %d is thinking\n", \
	get_miliseconds(data), philo->philo_nmbr);
	if (check_if_can_proceed(philo, data))
		return ;
}