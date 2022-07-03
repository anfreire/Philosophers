/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfreire <anfreire@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:19:48 by anfreire          #+#    #+#             */
/*   Updated: 2022/07/03 15:26:08 by anfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	create_philos(t_data *data)
{
	int		i;
	
	i = 1;
	data->philo.philos = malloc(sizeof(pthread_t) * (data->nmbr_philos));
	while (i <= data->nmbr_philos)
	{
		data->nmbr_thread = i;
		if (i == 1)
		{
			if (gettimeofday(&data->t_start, NULL) != 0)
				return ;
		}
		if (pthread_create(&data->philo.philos[i], NULL, &routine, data) != 0)
			return ;
		usleep(1000);
		i++;
	}
}

void	join_philos(t_data *data)
{
	int	i;
	
	i = 0;
	while (i < data->nmbr_philos)
	{
		if (pthread_join(data->philo.philos[i], NULL) != 0)
			return ;
		i++;
	}
}

void	create_mutex(t_data *data)
{
	int		i;
	
	i = 0;
	data->philo.forks = malloc(sizeof(pthread_mutex_t) * (data->nmbr_philos));
	data->philo.cond = malloc(sizeof(pthread_cond_t) * (data->nmbr_philos));
	while (i < data->nmbr_philos)
	{
		if (pthread_mutex_init(&data->philo.forks[i], NULL) != 0)
			return ;
		if (pthread_cond_init(&data->philo.cond[i], NULL) != 0)
			return ;
		i++;
	}
}

void	destroy_mutex(t_data *data)
{
	int	i;
	
	i = 0;
	while (i < data->nmbr_philos)
	{
		if (pthread_mutex_destroy(&data->philo.forks[i]) != 0)
			return ;
		if (pthread_cond_destroy(&data->philo.cond[i]) != 0)
			return ;
		i++;
	}
}