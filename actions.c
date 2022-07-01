/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfreire <anfreire@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:27:59 by anfreire          #+#    #+#             */
/*   Updated: 2022/07/01 13:14:12 by anfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	philo_eat_v1(t_data *philo, int philo_nmbr)
{
	int	i1;
	int	i2;
	
	i1 = philo_nmbr - 1;
	i2 = philo_nmbr;
	if (philo->forks[i2] == 0)
	{
		philo->forks[i1] = 0;
		philo->forks[0] = 0;
		usleep(philo->t_eat / 1000);
		philo->forks[i1] = philo_nmbr - 1;
		philo->forks[0] = 1;
		return ;
	}
	philo_eat_v2(philo, philo_nmbr);
}

void	philo_eat_v2(t_data *philo, int philo_nmbr)
{
	int	i1;
	int	i2;
	
	i1 = philo_nmbr - 1;
	i2 = philo_nmbr;
	philo->forks[i1] = 0;
	philo->forks[i2] = 0;
	usleep(philo->t_eat / 1000);
	philo->forks[i1] = philo_nmbr - 1;
	philo->forks[i2] = philo_nmbr;
}