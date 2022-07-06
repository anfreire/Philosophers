/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfreire <anfreire@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:52:07 by anfreire          #+#    #+#             */
/*   Updated: 2022/07/07 00:54:24 by anfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <time.h>
#include <string.h>

typedef struct s_data t_data;

typedef	struct s_philo
{
	int				philo_nmbr;
	int				is_full;
	pthread_t		philo;
	pthread_mutex_t	forks;
	t_data			*data;

}				t_philo;

struct s_data
{
	int				nmbr_philos;
	int				*forks;
	struct	timeval	t_start;
	long			t_eat;
	long			t_die;
	long			t_sleep;
	int				nmbr_philo_eat;
	int				philos_alive;
	t_philo			*philos;
};

//actions
void	philo_eats(t_philo *philo, t_data *data);
void	philo_sleeps(t_philo *philo, t_data *data);
void	philo_thinks(t_philo *philo, t_data *data);
int		can_philo_eat(t_philo *philo, t_data *data);

//routine
void	*routine(void *args);
void	philo_died(t_philo *philo, t_data *data);

//errors
int			check_if_digit(char *str);
int			check_args(int argc, char **argv);
void		atributte_args(int argc, char **argv, t_data *data);
long long	get_miliseconds(t_data *data);


//process
void	create_philos(t_data *data);
void	destroy_philo(t_data *data);


//utils
int		ft_isdigit(char *str);
int		ft_atoi(char *str);

#endif