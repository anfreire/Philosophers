/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfreire <anfreire@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:19:48 by anfreire          #+#    #+#             */
/*   Updated: 2022/07/07 01:15:50 by anfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	create_philos(t_data *data)
{
	int	i;

	i = 0;
	data->philos = malloc(sizeof(t_philo) * data->nmbr_philos);
	data->forks = malloc(sizeof(int) * data->nmbr_philos);
	while (i < data->nmbr_philos)
	{
		if (i == 0)
			gettimeofday(&data->t_start, NULL);
		data->forks[i] = 1;
		data->philos[i].data = data;
		data->philos[i].is_full = 0;
		data->philos[i].philo_nmbr = i + 1;
		pthread_create(&data->philos[i].philo, NULL, &routine, &data->philos[i]);
		pthread_mutex_init(&data->philos[i].forks, NULL);
		i++;
	}
}

void	destroy_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nmbr_philos)
	{
		pthread_join(data->philos[i].philo, NULL);
		pthread_mutex_destroy(&data->philos[i].forks);
		i++;
	}
}

void	free_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nmbr_philos)
	{
		free(&data->philos[i].philo);
		free(&data->philos[i].forks);
		i++;
	}
}