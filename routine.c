/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfreire <anfreire@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:27:59 by anfreire          #+#    #+#             */
/*   Updated: 2022/07/29 02:59:39 by anfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	check_if_all_philos_eaten(t_data *data)
{
	int	i;

	i = -1;
	if (data->nmbr_philo_eat == 0)
		return ;
	while (++i < data->nmbr_philos)
	{
		if (data->philos[i].philos_eated != data->nmbr_philo_eat)
			return ;
	}
	data->philo_died = 1;
}

void	check_if_philo_is_dead(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nmbr_philos)
	{
		if (get_miliseconds_hunger(&data->philos[i]) >= (long long)data->t_die)
		{
			if (data->philo_died == 1)
				return ;
			data->philo_died = 1;
			printf("ms:%lld		Philo %d has died*******\n", \
			get_miliseconds(data), data->philos[i].philo_nmbr);
			return ;
		}
	}
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
	gettimeofday(&philos->t_full, NULL);
	while (1)
	{
		if (routine_aux(philos, data) == 1)
			return (NULL);
		if (data->t_die == 1)
			return (NULL);
	}
	return (NULL);
}
