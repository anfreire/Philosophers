/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfreire <anfreire@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:27:59 by anfreire          #+#    #+#             */
/*   Updated: 2022/07/01 13:20:57 by anfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	philo_eat_v1(t_data *data, int philo_nmbr)
{
	int	i1;
	int	i2;
	
	i1 = philo_nmbr - 1;
	i2 = philo_nmbr;
	if (data->philo.forks[i2] == 0)
	{
		data->philo.forks[i1] = 0;
		data->philo.forks[0] = 0;
		usleep(data->t_eat / 1000);
		data->philo.forks[i1] = philo_nmbr - 1;
		data->philo.forks[0] = 1;
		return ;
	}
	philo_eat_v2(data, philo_nmbr);
}

void	philo_eat_v2(t_data *data, int philo_nmbr)
{
	int	i1;
	int	i2;
	
	i1 = philo_nmbr - 1;
	i2 = philo_nmbr;
	data->philo.forks[i1] = 0;
	data->philo.forks[i2] = 0;
	usleep(data->t_eat / 1000);
	data->philo.forks[i1] = philo_nmbr - 1;
	data->philo.forks[i2] = philo_nmbr;
}