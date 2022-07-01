/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfreire <anfreire@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:19:48 by anfreire          #+#    #+#             */
/*   Updated: 2022/07/01 13:14:47 by anfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	atributte_args(int argc, char **argv, t_data *philo)
{
	philo->nmbr_philos = ft_atoi(argv[1]);
	philo->t_die = ft_atoi(argv[2]);
	philo->t_eat = ft_atoi(argv[3]);
	philo->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo->nmbr_philo_eat = ft_atoi(argv[5]);
	else
		philo->nmbr_philo_eat = 0;
	put_forks(philo);
}

void	put_forks(t_data *philo)
{
	int	i;
	
	i = 0;
	philo->forks = malloc(sizeof(int) * (philo->nmbr_philos + 1));
	while (i < philo->nmbr_philos)
	{
		philo->forks[i] = i + 1;
		i++;
	}
	philo->forks[i] = 0;
}