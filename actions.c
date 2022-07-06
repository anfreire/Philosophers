/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfreire <anfreire@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 08:56:13 by anfreire          #+#    #+#             */
/*   Updated: 2022/07/06 23:54:25 by anfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	can_philo_eat(t_philo *philo, t_data *data)
{
	int	i1;
	int	i2;

	i1 = philo->philo_nmbr - 1;
	i2 = philo->philo_nmbr;
	if (data->philos_alive == 0)
		return (0);
	if (philo->philo_nmbr == philo->data->nmbr_philos)
		i2 = 0;
	if (data->forks[i1] == 0 || data->forks[i2] == 0)
		return (0);
	else
		return (1);
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
	if (data->philos_alive == 0)
		return ;
	mutex_lock(data, i1, i2);
	philo->is_full = 1;
	printf("ms:%lld		Philo %d has taken a fork\n", get_miliseconds(data), philo->philo_nmbr);
	printf("ms:%lld		Philo %d has taken a fork\n", get_miliseconds(data), philo->philo_nmbr);
	printf("ms:%lld		Philo %d is eating\n", get_miliseconds(data), philo->philo_nmbr);
	philo->is_full = 0;
	usleep(data->t_eat * 1000);
}

void	philo_sleeps(t_philo *philo, t_data *data)
{
	int	i1;
	int	i2;

	i1 = philo->philo_nmbr - 1;
	i2 = philo->philo_nmbr;
	if (philo->philo_nmbr == philo->data->nmbr_philos)
		i2 = 0;
	if (data->philos_alive == 0)
		return ;
	pthread_mutex_unlock(&data->philos[i1].forks);
	pthread_mutex_unlock(&data->philos[i2].forks);
	data->forks[i1] = 1;
	data->forks[i2] = 1;
	printf("ms:%lld		Philo %d is sleeping\n", get_miliseconds(data), philo->philo_nmbr);
	usleep(data->t_sleep * 1000);
}

void	philo_thinks(t_philo *philo, t_data *data)
{
	if (data->philos_alive == 0)
		return ;
	printf("ms:%lld		Philo %d is thinking\n", get_miliseconds(data), philo->philo_nmbr);
}