/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfreire <anfreire@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:19:48 by anfreire          #+#    #+#             */
/*   Updated: 2022/07/01 17:51:23 by anfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	atributte_args(int argc, char **argv, t_data *data)
{
	data->nmbr_philos = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->nmbr_philo_eat = ft_atoi(argv[5]);
	else
		data->nmbr_philo_eat = 0;
	put_forks(data);
}

void	put_forks(t_data *data)
{
	int	i;
	
	i = 0;
	data->philo.forks = malloc(sizeof(int) * (data->nmbr_philos + 1));
	while (i < data->nmbr_philos)
	{
		data->philo.forks[i] = i + 1;
		i++;
	}
	data->philo.forks[i] = 0;
}

void	create_philos(t_data *data)
{
	int		i;
	
	i = 1;
	data->philo.philos = malloc(sizeof(pthread_t) * (data->nmbr_philos));
	while (i <= data->nmbr_philos)
	{
		data->nmbr_thread = i;
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