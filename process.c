/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfreire <anfreire@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:19:48 by anfreire          #+#    #+#             */
/*   Updated: 2022/07/26 21:55:38 by anfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	create_philos(t_data *data)
{
	int	i;

	i = -1;
	data->philos = malloc(sizeof(t_philo) * data->nmbr_philos);
	data->forks = malloc(sizeof(int) * data->nmbr_philos);
	while (++i < data->nmbr_philos)
		pthread_mutex_init(&data->philos[i].forks, NULL);
	i = -1;
	while (++i < data->nmbr_philos)
	{
		if (i == 0)
			gettimeofday(&data->t_start, NULL);
		data->forks[i] = 1;
		data->philos[i].philos_eated = 0;
		data->philos[i].data = data;
		data->philos[i].philo_nmbr = i + 1;
		pthread_create(&data->philos[i].philo, NULL, &routine, \
		&data->philos[i]);
	}
}

void	destroy_philo(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nmbr_philos)
		pthread_join(data->philos[i].philo, NULL);
	i = -1;
	while (++i < data->nmbr_philos)
	{
		if (data->forks[i] == 0)
			pthread_mutex_lock(&data->philos[i].forks);
	}
	i = -1;
	while (++i < data->nmbr_philos)
		pthread_mutex_destroy(&data->philos[i].forks);
}
