/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfreire <anfreire@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:10:05 by anfreire          #+#    #+#             */
/*   Updated: 2022/07/17 18:09:26 by anfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_isdigit(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int		i;
	int		result;

	result = 0;
	i = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i++] - '0';
	}
	return (result);
}

long long	get_miliseconds(t_data *data)
{
	long long		sec;
	long long		usec;
	struct timeval	t_now;
	
	if (gettimeofday(&t_now, NULL) != 0)
				exit (1);
	sec = t_now.tv_sec - data->t_start.tv_sec;
	usec = t_now.tv_usec - data->t_start.tv_usec;
	return ((usec / 1000) + (sec * 1000));
}

int	check_if_can_proceed(t_philo *philo, t_data *data)
{
	if (data->philo_died == 1)
		return (1);
	check_if_philo_is_dead(data, philo);
	check_if_all_philos_eaten(data);
	if (data->philo_died == 1)
		return (1);
	else
		return (0);
}